let cells = document.querySelectorAll('.row > div');

let val = document.getElementById("player");

let y = 0;
for(var i = 0; i < cells.length; ++i){
    cells[i].addEventListener('click',cellClicked);
}


function cellClicked(){
    if((event.target.textContent == 'X')||(event.target.textContent == 'O')){
        val.value = "You are clicking on an Filled Space !";        
    }
    else{
        if(y%2 == 0){
            val.value = "Player X Turn !";
            event.target.textContent = 'X';
        }
        else{
            val.value = "Player O Turn !";
            event.target.textContent = 'O';
        }
        y++;
    }
    if(val.value.length == 18){
        location.reload();
    }
    if(y==9){
        val.value = "Draw ! ";
        
    }
    if(y == 10){
        location.reload();
    }
    check();
}

function check(){
    if((cells[0].textContent != "")&&(cells[0].textContent == cells[1].textContent)&&(cells[1].textContent==cells[2].textContent)){
        
        val.value = "Player "+cells[1].textContent+" has Won !";
        
    }
    else if((cells[3].textContent != "")&&(cells[3].textContent == cells[4].textContent)&&(cells[4].textContent==cells[5].textContent)){
        
        val.value = "Player "+cells[3].textContent+" has Won !";
        
    }
    else if((cells[6].textContent != "")&&(cells[6].textContent == cells[7].textContent)&&(cells[7].textContent==cells[8].textContent)){
        val.value = "Player "+cells[6].textContent+" has Won !";
        
    }
    else if((cells[0].textContent != "")&&(cells[0].textContent == cells[4].textContent)&&(cells[4].textContent==cells[8].textContent)){
        val.value = "Player "+cells[6].textContent+" has Won !";
        
    }
    else if((cells[2].textContent != "")&&(cells[2].textContent == cells[4].textContent)&&(cells[4].textContent==cells[6].textContent)){
        val.value = "Player "+cells[6].textContent+" has Won !";
        
    }
    else if((cells[0].textContent != "")&&(cells[0].textContent == cells[3].textContent)&&(cells[3].textContent==cells[6].textContent)){
        val.value = "Player "+cells[6].textContent+" has Won !";
        
    }
    else if((cells[1].textContent != "")&&(cells[1].textContent == cells[4].textContent)&&(cells[4].textContent==cells[7].textContent)){
        val.value = "Player "+cells[6].textContent+" has Won !";
        
    }
    else if((cells[2].textContent != "")&&(cells[2].textContent == cells[5].textContent)&&(cells[5].textContent==cells[8].textContent)){
        val.value = "Player "+cells[6].textContent+" has Won !";
        
    }
}
