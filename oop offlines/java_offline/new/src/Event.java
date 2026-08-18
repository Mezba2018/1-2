/* This class stores the following information about an event: name, starting date, location and list of students registered for the event. */
public class Event {
    private String eventName;
    private String eventDate; // store in the format YYYY-MM-DD
    private String eventLocation;
    private Student[] registeredStudents;
    int participantsAdded = 0; //variable to keep track of number of participants so far added

    //Task: Write code for the constructor below to initialize the member variables properly
    public Event(String eventName, String eventDate, String eventLocation, int maximumParticipants) {
        //write your code here
        // my code s
        this.eventName=eventName;
        this.eventDate=eventDate;
        this.eventLocation=eventLocation;
        this.registeredStudents=new Student[maximumParticipants];
        this.participantsAdded=0;
    
        //my code e, r o ekta lekha lagbe
    }

    // Task: Write getters and setters for Event attributes as required
    //my code s
public void seteventName(String eventName){
    this.eventName=eventName;
}
public void seteventDate(String eventDate){
    this.eventDate=eventDate;
}
public void seteventNLocation(String eventLocation){
    this.eventLocation=eventLocation;
}
public String geteventName(){
    return this.eventName;
}
public String geteventDate(){
    return this.eventDate;
}
public String geteventLocation(){
    return this.eventLocation;
}
public int length(){
    return participantsAdded;
}
 

    //my code e
    
    
    // Task: Write your code for the function below. This functions adds a participant to this event. Check for the following cases: (i) total participant count does not exceed the maximum participant count, (ii) the studentId is not already added.
    public void addParticipant(Student student) {
        // write your code here 


         if(isRegistered(student.getId()))
         {
            System.out.println("student already exists");
         }
        else if(participantsAdded<registeredStudents.length)
        {
            registeredStudents[participantsAdded]=student;
            participantsAdded++;
        }
        else
        {
            System.out.println("Candidate capacity exceed!!!");
        }

    }

    
    //Task: Write code for the function below. This function shows the details of an event. Make sure your output matches with the supplied sample output.
    public void showDetails() {
        //Write your code here
        System.out.println("Name: "+eventName);
        System.out.println("Date: "+eventDate);
        System.out.println("Location: "+eventLocation);
        System.out.println("Registered Participants:");

        for (int i = 0; i < participantsAdded; i++) {
            Student student = registeredStudents[i];
            System.out.println(" Name: " + student.getName() + ", Id: " + student.getId());
        
        }
    }

    //Task: Write code for the function below. This function check whether the studentId in the argument has registered for this event or not. Return true if registered, otherwise return false.
    public boolean isRegistered(String studentId) {
        //Write your code here
        int i;
        for(i=0;i<participantsAdded;i++){
            if(registeredStudents[i].getId().equals(studentId))
            {
                return true;
            }
        }
        return false;
        
    }

    // Task: Write code for the function below. This function removes a participant from this event. Check for the following cases: (i) the student Id is not regiseterd. 
    public void removeParticipant(String studentId) {
        //Write your code here
        int i, findex=-1;
        for(i=0;i<participantsAdded;i++)
        {
            if(isRegistered(registeredStudents[i].getId())){
                findex=i;
                break;
            }
        }
        if(findex!=-1)
        {
            for(i=findex;i<participantsAdded-1;i++)
            {
                registeredStudents[i]=registeredStudents[i+1];
            }
            registeredStudents[participantsAdded-1]=null;
            System.out.println("Participant with studentId " + studentId + " has been removed.");
            participantsAdded--;

        }
        else{
            System.out.println("Participant with studentId " + studentId + "is not registered.");
        }
        
    }

}