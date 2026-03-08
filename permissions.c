// Challenge: User Permission System
//
// Using a User struct and Roles enum, build a small permission system:
//
// 1. Add an array of 5 users with a mix of ADMIN, USER, and GUEST roles
// 2. Write a function const char* getRoleName(Roles role) that returns the role as a string
// 3. Write a function int hasPermission(User *user, const char *action) that checks permissions:
//    - ADMIN can: "read", "write", "delete"
//    - USER can: "read", "write"
//    - GUEST can: "read" only
//    - Return 1 for allowed, 0 for denied
// 4. Write a function void printUsers(User users[], int count) that prints all users and their roles
// 5. In main, loop through all users and test each one against "read", "write", and "delete"
//
// Bonus: Add a login field (int loggedIn) to the struct. Deny all actions if the user isn't logged in.




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
      ADMIN,
      USER,
      GUEST
  } Roles;

typedef struct{
    char name[100];
    Roles role;
    int loggedIn;
}User;

const char* getRoleName(Roles role);
int hasPermissions(User *user, const char *action);
void printUsers(User users[], int count);

int main() {

    User user[5] = {{"Sally Saw", ADMIN, 1}, {"John Wilks", GUEST, 0}, {"Carry Cam", USER, 1}, {"Bernie Pakman", USER, 0}, {"Pelle Nusiens", ADMIN, 1}};

    for(int i = 0; i < sizeof(user) / sizeof(user[0]); i++) {

       printf("%s (%s) -> write: %s \n", user[i].name, getRoleName(user[i].role), hasPermissions(&user[i], "write") ? "ALLOWED" : "DENIED");

        printf("%s (%s) -> read: %s \n", user[i].name, getRoleName(user[i].role), hasPermissions(&user[i], "read") ? "ALLOWED" : "DENIED");

        printf("%s (%s) -> delete: %s \n", user[i].name, getRoleName(user[i].role), hasPermissions(&user[i], "delete") ? "ALLOWED" : "DENIED");
    }
    return 0;
}

const char* getRoleName(Roles role){

    if(role == ADMIN) {
        return "Admin";
    } else if (role == GUEST) {
        return "Guest";
    } else if (role == USER ) {
        return "User";
    }
    return "Unknown";
}

int hasPermissions(User *user, const char *action) {
    if (!user->loggedIn) {
        return 0;
    }
    if (strcmp(action, "read") == 0) {
        return 1;
    } else if (strcmp(action, "write") == 0) {
        switch (user->role) {
            case ADMIN: return 1;
            case GUEST: return 0;
            case USER: return 1;
        }
    } else if (strcmp(action, "delete") == 0) {
        switch (user->role) {
            case ADMIN: return 1;
            case GUEST: return 0;
            case USER: return 0;
        }
    }
    return 0;
}

void printUsers(User users[], int count) {
    for (int i = 0; i < count; i++) {
        printf("User %d: %s Role: %s\n",i,users[i].name,getRoleName(users[i].role));
    }
}
