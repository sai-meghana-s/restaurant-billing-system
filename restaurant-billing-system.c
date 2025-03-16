#include<stdio.h>

struct item{
    int productno;
    char itemname[100];
    float price;
};

int main(){
    int quantity,i=0,j,n=100,member,itno,order,list,a[100],cardno,card,b[100];
    float totalamount=0,discount;

    struct item item_list[24]=  {
        {1 ,"Idli\t " ,30 },
        {2 ,"Vada\t " ,15 },
        {3 ,"Poori\t " ,40 },
        {4 ,"Plain Dose " ,30 },
        {5 ,"Masale Dose " ,40 },
        {6 ,"Set Dose " ,30 },
        {7 ,"Onion Dose " ,35 },
        {8 ,"Rice bath " ,30 },
        {9 ,"Peas Pulav " ,50 },
        {10 ,"Bisibele Bath " ,30 },
        {11 ,"Puliogre " ,30 },
        {12 ,"Lemon Rice " ,30 },
        {13 ,"Curd Rice " ,20 },
        {14 ,"Meals\t " ,50 },
        {15 ,"Poha\t " ,30 },
        {16 ,"Upma\t " ,20 },
        {17 ,"Kesari Bath " ,20 },
        {18 ,"Pongal\t " ,20 },
        {19 ,"Gulab Jamun " ,10 },
        {20 ,"Tea\t " ,10 },
        {21 ,"Coffee\t " ,10 },
        {22 ,"Badam Milk " ,15 },
        {23 ,"Butter Milk " ,15 },
        {24 ,"Lemon Juice " ,15 },
        };

    printf("===============================================\n");
    printf("\t\tWelcome to KASTURI UPAHAR\n");
    printf("===============================================\n");
    printf("Item Number\tItem Name\t\tPrice\n");

    for(i=0;i<24;i++){ 
        printf("\t%d\t%s\t\t%.2f\n",item_list[i].productno,item_list[i].itemname,item_list[i].price);
    }
    i=0;

    printf("\n\nPress 1 to start ordering your favorite meal\n");
    scanf("%d",&order);
    
    while(order!=1){
        printf("Please press 1 to order\n");
        scanf("%d",&order);
    }
        
    while(order==1){
        printf("Enter the Item number you wish to order\n");
        scanf("%d",&itno);
        if(itno>=0 && itno<25){
            printf("Enter the quantity of item you wish to order\n");
            scanf("%d",&quantity);
            while(quantity>20){
                printf("Sorry,large quantity requires pre-orders.\nPlease enter a quantity less than 20\n");
                scanf("%d",&quantity);
            }
            a[i]=itno-1;
            b[i]=quantity;
            i++;
            j=i;
            if(quantity<20){
                totalamount=totalamount+(item_list[itno-1].price*quantity);
            }
        }
        else
        {
        printf("Invalid choice\n");
        }

        printf("Press 1 to order more\n");
        scanf("%d",&order);
    }

    printf("Press 1 if you have a membership card\n");
    scanf("%d",&card);

    while(card==1){
        printf("Enter your card number:");
        scanf("%d",&cardno);
        
        if(cardno>1000 && cardno<2000){
            member=1;
            break;
        }
        else if(cardno>2000 && cardno<3000){
            member=2;
            break; 
        }
        else {
        printf("Invalid card number\n");
        printf("Press 1 if you have a membership card\n");
        scanf("%d",&card);
        }
    }

    printf("\n\n\t\t\t********INVOICE******\n\n");
    printf("Slno\tItem Name\t\tPrice\t\tQuantity\tAmount\t\n");
    
    for(i=0;i<j;i++){
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%.2f\n",i+1,item_list[a[i]].itemname,item_list[a[i]].price,b[i],item_list[a[i]].price*b[i]);
    }
    switch(member) {
        case 1 :    printf("\nCongrats!!You availed an discount of 20 percent for your gold membership\n");
                    discount = 0.2*totalamount;
                    totalamount=totalamount-discount;
                    printf("\t\t\tDiscount =\t- %.2f\n",discount);
                    break;
        case 2:     printf("\nCongrats!!You availed an discount of 10 percent for your silver membership\n");
                    discount = 0.1*totalamount;
                    totalamount=totalamount-discount;
                    printf("\t\t\tDiscount =\t- %.2f\n",discount);
                    break;
    }

    printf("\n\t\t\tAmount payable=\t %.2f\n",totalamount);
    printf("\t\t\t*********************\n");
    printf("\t\t\tThank you! Have a nice day!!\n");
    printf("\t\t\t\tVisit Again\n");
    return 0;

    } 