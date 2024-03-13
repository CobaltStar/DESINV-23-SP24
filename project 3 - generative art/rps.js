let players = [];
let numRocks = 15;
let numPapers = 15;
let numScissors = 15;
let winner;

function setup() {
  createCanvas(1500, 900);
  for (let i = 0; i < numRocks; i++) {
    players.push(new Player(random(width), random(height), 'rock'));
  }
  for (let i = 0; i < numPapers; i++) {
    players.push(new Player(random(width), random(height), 'paper'));
  }
  for (let i = 0; i < numScissors; i++) {
    players.push(new Player(random(width), random(height), 'scissors'));
  }
	
	rockImg = loadImage("./rock.png");
	paperImg = loadImage("./paper.png");
	scissorsImg = loadImage("./scissors.png");
	
	helveticaFont = loadFont('https://cdnjs.cloudflare.com/ajax/libs/topcoat/0.8.0/font/SourceCodePro-Bold.otf');
	textFont(helveticaFont);
}

function draw() {
  background(220);
  // Check for the winner
  let classCounts = {
    'rock': 0,
    'paper': 0,
    'scissors': 0
  };
  
  for (let player of players) {
    classCounts[player.choice]++;
  }
  
  // Show each player
  for (let player of players) {
    player.show();
    player.move();
    player.checkCollision();
  }
  
  if (classCounts['rock'] === 0  && classCounts['paper'] === 0 ||
    classCounts['rock'] === 0 && classCounts['scissors'] === 0 ||
    classCounts['paper'] === 0 && classCounts['scissors'] === 0) {
    winner = Object.keys(classCounts).find(key => classCounts[key] > 0);
    textSize(32);
    textAlign(CENTER, CENTER);
    
    // Show each player
    for (let player of players) {
      player.show();
      player.move();
      player.checkCollision();
    }
      
    fill(0, 0, 0);
		winner_uppercase = winner.charAt(0).toUpperCase() + winner.slice(1);
    text(`${winner_uppercase} Wins!`, width / 2, height / 2);
    noLoop();
  }
    
}

class Player {
  constructor(x, y, choice) {
    this.x = x;
    this.y = y;
    this.choice = choice;
    this.radius = 20;
    
    this.maxSpeed = 2;
    this.speedX = random(-this.maxSpeed, this.maxSpeed);
    this.speedY = random(-this.maxSpeed, this.maxSpeed);
  }

  show() {
    if (this.choice === 'rock') {
			image(rockImg, this.x, this.y);
    } else if (this.choice === 'paper') {
			image(paperImg, this.x, this.y);
    } else if (this.choice === 'scissors') {	
			image(scissorsImg, this.x, this.y);
    }
  }

  move() {
    this.x += this.speedX;
    this.y += this.speedY;

    // bounce off walls
    if (this.x > width - this.radius || this.x < this.radius) {
      this.speedX *= -1;
    }
    if (this.y > height - this.radius || this.y < this.radius) {
      this.speedY *= -1;
    }
  }

  checkCollision() {
    for (let other of players) {
      if (other !== this) {
        let d = dist(this.x, this.y, other.x, other.y);
        if (d < this.radius + other.radius) {
          if ((this.choice === 'rock' && other.choice === 'scissors') ||
              (this.choice === 'paper' && other.choice === 'rock') ||
              (this.choice === 'scissors' && other.choice === 'paper')) {
            other.choice = this.choice;
          } else {
            this.choice = other.choice;
          }
        }
      }
    }
  }
}
