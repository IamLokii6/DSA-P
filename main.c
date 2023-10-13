#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "./stack/stack.h"
#include "./infix_to_postfix/infixtopostfix.h"
#include "./postfix_eval/postfix.h"
#include "./bracket_matching/bracket.h"
#include "./binnary_tree/binnary.h"
#include "./tree_traversal/tree_trav.h"
#include "./shortest_distance/shortestdistance.h"

int main()
{
    int option;
    int size;
    while (1)
    {
        printf("Enter:\n1)Stack Operations \n2)Infix to Postfix Conversion \n3)Postfix Evaluation \n4)bracket matching \n5)Binary tree Operations \n6)Shortest distance Using Dijkstra");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            stack *s = createStack();
            int element;
            do
            {
                printf("1)Push an element into stack \n2)Pop the topmost element \n3)Peek \n4)Print stack \n5)Exit\n");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                {
                    fflush(stdin);
                    printf("Enter the element to push:");
                    scanf("%d", &element);
                    push(s, element);
                    break;
                }

                case 2:
                {
                    int data = pop(s);
                    if (data)
                    {
                        printf("The poped element is:%d\n", data);
                    }
                    break;
                }
                case 3:
                {
                    printf("The element at stack top:%d\n", peek(s));
                    break;
                }

                case 4:
                {
                    printStack(s);
                    break;
                }

                case 5:
                    break;

                default:
                    printf("Invalid input\n");
                }
            } while (option != 5);
            break;
        }
        case 2:
        {
            char infixExp[50];
            printf("Enter infix expression:");
            scanf("%s", infixExp);
            char *postfixExp = infixToPostfix(infixExp);
            printf("%s", postfixExp);
            break;
        }

        case 3:
        {
            char postfix[50];
            printf("Enter postfix expression:");
            scanf("%s", postfix);
            printf("Result:%d\n", evaluatePostfix(postfix));
            break;
        }

        case 4:
        {
            char exp[50];
            printf("Enter expression:");
            scanf("%s", exp);
            if (areBracketsBalanced(exp))
                printf("Balanced \n");
            else
                printf("Not Balanced \n");
            break;
        }
        
        case 5:
        {
            int treeCreated = 0;
            TreeNode* root = NULL;
            int data;

            do
            {
                printf("Pick one choise \n1)Insert data in Binary Tree \n2)Delete Data from Binary Tree\n3)Inorder Traversal \n4)Preorder Tracersal \n5)Postorder Traversal:");

                scanf("%d", &option);
                switch (option)
                {
                case 1:
                {
                    printf("\nEnter the data to be inserted:");
                    fflush(stdin);
                    scanf("%d", &data);
                    if (treeCreated)
                    {
                        insert(root, data);
                    }
                    else
                    {
                        root = insert(root, data);
                        treeCreated = 1;
                    }
                    break;
                }

                case 2:
                {
                    break;
                }
                case 3:
                {
                    inorderTraversal(root);
                    break;
                }
                case 4:
                {
                    preorderTraversal(root);
                    break;
                }
                case 5:
                {
                    postorderTraversal(root);
                    break;
                }

                default:
                    break;
                }

            }while(option!=6);
            break;
        }

        case 6: {
            
                int graph[V][V] = {
                    {0, 4, 0, 0, 0, 0, 0, 8, 0},
                    {4, 0, 8, 0, 0, 0, 0, 11, 0},
                    {0, 8, 0, 7, 0, 4, 0, 0, 2},
                    {0, 0, 7, 0, 9, 14, 0, 0, 0},
                    {0, 0, 0, 9, 0, 10, 0, 0, 0},
                    {0, 0, 4, 0, 10, 0, 2, 0, 0},
                    {0, 0, 0, 14, 0, 2, 0, 1, 6},
                    {8, 11, 0, 0, 0, 0, 1, 0, 7},
                    {0, 0, 2, 0, 0, 0, 6, 7, 0}
                };
                printf("Running Dijkstra's Algorithm...\n");
                dijkstra(graph, 0);
                break;
        }

        default:
            printf("Exiting the program");
            exit(0);
        }
    }
}