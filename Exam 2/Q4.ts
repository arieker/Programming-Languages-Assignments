interface WeLoveCOP4020 {
    sayIt(): void;
}

class Barista implements WeLoveCOP4020 {
    sayIt(): void {
        console.log("As a barista, I majored in CS and the job market made me end up here!");
    }
}

class SoftwareEngineer implements WeLoveCOP4020 {
    sayIt(): void {
        console.log("As a software engineer, I ended up not being able to find a job and might need to be a barista!");
    }
}

class PsychologyMajor implements WeLoveCOP4020 {
    sayIt(): void {
        console.log("As a psychology major I chose an easier major and also can't find a job!");
    }
}

const barista = new Barista();
const softwareEngineer = new SoftwareEngineer();
const psychologyMajor = new PsychologyMajor();

barista.sayIt();
softwareEngineer.sayIt();
psychologyMajor.sayIt();