interface Candy {
    type: string;
    flavor: string;
}

class Chocolate implements Candy {
    type: string;
    flavor: string;

    constructor(flavor: string) {
        this.type = "Chocolate";
        this.flavor = flavor;
    }
}

class Lollipop implements Candy {
    type: string;
    flavor: string;

    constructor(flavor: string) {
        this.type = "Lollipop";
        this.flavor = flavor;
    }
}

class GummyBear implements Candy {
    type: string;
    flavor: string;

    constructor(flavor: string) {
        this.type = "Gummy Bear";
        this.flavor = flavor;
    }
}

class CandyFactory {
    static createCandy(type: string, flavor: string): Candy {
        switch (type.toLowerCase()) {
            case "chocolate":
                return new Chocolate(flavor);
            case "lollipop":
                return new Lollipop(flavor);
            case "gummy bear":
                return new GummyBear(flavor);
            default:
                throw new Error(`Unknown candy type: ${type}`);
        }
    }
}

// Usage
const candy1: Candy = CandyFactory.createCandy("Chocolate", "Milk");
console.log(candy1);

const candy2: Candy = CandyFactory.createCandy("Lollipop", "Strawberry");
console.log(candy2);

const candy3: Candy = CandyFactory.createCandy("Gummy Bear", "Orange");
console.log(candy3);
