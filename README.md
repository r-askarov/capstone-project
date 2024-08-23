Docker image of this program: https://hub.docker.com/repository/docker/askar025/drone_sim/general


**Project Description:**

This project simulates a package delivery using a drone in a 3D simulation of the UMN campus.

This project was developed using an Agile Scrum methodology, where me and my classmate worked extensively with Git (version control) and Jira.

**How to run the simulation:**

Using Docker, one can pull the docker image from the DockerHub link at the top and run it locally using the command specified in the overview found in that same link, which will start the server at http://localhost:8081/ where the simulation webpage will appear.

Once the simulation webpage is open, users need to open the schedule page, found at http://localhost:8081/schedule.html or by clicking on the button on the right side of the simulation.

In the schedule page, users will: 
1. Enter a name for the delivery
2. Choose a movement strategy - the search/path-finding algorithm that will determine the drone's route to the destination
3. Pick 2 points on the map of the UMN campus - one for the inital package location, and one for its destination.

Finally, click "Schedule Delivery" at the bottom of the schedule page.