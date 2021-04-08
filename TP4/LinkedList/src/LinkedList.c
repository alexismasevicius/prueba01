#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int aux;
    int i;

    if(this!=NULL)
    {
        aux=ll_len(this);
        if(nodeIndex>=0 && aux>nodeIndex)
        {
            pNode=this->pFirstNode; //asigno pNode al primer lugar de la LL.
            for(i=0; i<nodeIndex; i++)
            {
                pNode= pNode->pNextNode; //recorre todos los nodos contenidos en la LL
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    //Node* next;
    Node* nuevoNodo;
    int len;

    nuevoNodo=(Node*)malloc(sizeof(Node));
    len=ll_len(this);
    nuevoNodo->pElement=pElement;


    if(this!=NULL && nuevoNodo!=NULL)
    {
        if(len==0 && nodeIndex==0) // si coinciden
        {
            this->pFirstNode=nuevoNodo;//se asigna al primer nodo
            this->size++;
            returnAux=0;
            //pNewNode->pNextNode=NULL; //no hace falta
        }
        else
        {
            if(len>0 && len==nodeIndex) //si es mayor a 0 e igual al tamanio
            {
                prev=getNode(this,nodeIndex-1);//
                prev->pNextNode=nuevoNodo;//asigno la dir de memoria del nuevo nodo
                returnAux=0;
                this->size++;
            }
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice = 0;
    //Node* actual; ???

    if(this!=NULL)
    {
        indice=ll_len(this); //cantidad de elementos = indice nuevo elemento
        returnAux=addNode(this,indice,pElement);
    }

    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoAux;

    nodoAux=getNode(this, index);
    if(nodoAux!=NULL)
    {
        returnAux=nodoAux->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;

    actual=getNode(this,index);

    if(actual!=NULL)
    {
        actual->pElement=pElement;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* actual;
    Node* next;
    Node* prev;
    //int indice = 0; ??
    int len;

    len=ll_len(this);

    if(this!=NULL)
    {
        if(index==0)
        {
            actual=getNode(this,index);
            this->pFirstNode=NULL;
            free(actual);
            this->size=0;
            returnAux=0;
        }
        else
        {
            if(index>0 && index<len)
            {
                actual=getNode(this,index);
                next=getNode(this,index+1);
                prev=getNode(this,index-1);
                if(actual!=NULL && prev!=NULL)
                {
                    prev->pNextNode=next;
                    free(actual);
                    this->size--;
                    returnAux=0;
                }
            }
        }

    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    //Node* nodo;
    int i;
    int len;
    int lastNodeIndex;

    if(this!=NULL)
    {
        len=ll_len(this);
        lastNodeIndex=len-1;

        for(i=0;i<len;i++)
        {
            ll_remove(this,lastNodeIndex-i);//borra de atras para adelante
        }
        returnAux=0;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodo;
    int len;

    len=ll_len(this);

    if(this!=NULL)
    {
        for(i=0;i<len;i++)
        {
           nodo=getNode(this,i);

           if(nodo->pElement==pElement)
           {
               returnAux=i;
           }

        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;

    len=ll_len(this);

    if(this != NULL)
    {
        if(len>0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    len=ll_len(this);

    if(this!=NULL)
    {
        if(index>-1 && index<=len) // menor o igual porque puede querer agregar al final
        {
            addNode(this, index, pElement);
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodo;

    int len;

    len=ll_len(this);

   if(this!=NULL && index>-1 && index<len)
    {

        nodo=getNode(this,index);
        returnAux=nodo->pElement;
        ll_remove(this,index); // pero el free no borraria todo? o no borra pElement?
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodo;
    int i;
    int len;

    len=ll_len(this);

    if(this!=NULL)
    {
        returnAux=0;
        for(i=0;i<len;i++)
        {
            nodo=getNode(this,i);
            if(nodo->pElement==pElement)
            {
                returnAux=1;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node* nodo;
    Node* nodoDos;


    int i;
    int j;
    int len;
    int lenDos;
    int flag = 0;

    len=ll_len(this);
    lenDos=ll_len(this2);

    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;
        for(i=0;i<lenDos;i++)
        {
            nodoDos=getNode(this2,i);
            for(j=0;j<len;i++)
            {
                nodo=getNode(this,i);
                if(nodoDos->pElement==nodo->pElement)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                returnAux=0;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;
    int len;

    len=ll_len(this);
    if(this!=NULL && from>=0 && from<=to && to<=len)
    {
        cloneArray=ll_newLinkedList();

            for(i=from;i<to;i++)   //copiar solo los elementos pasados de from a to
            {
                pElement=ll_get(this,i);
                ll_add(cloneArray,pElement);
            }
    }


    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;

    if(this!=NULL)
    {
        len=ll_len(this);
        cloneArray=ll_subList(this,0,len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    void* pAuxTwo;
    void* aux;
    int i;
    int j;
    int len;

    if(this!=NULL && pFunc!=NULL && order>-1 && order<2)
    {
        returnAux=0;

        len=ll_len(this);

        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                pAux=ll_get(this, i);
                pAuxTwo=ll_get(this, j);
                if(order==1)
                {
                    if(pFunc(pAux,pAuxTwo)==1)
                    {
                        aux=pAux;
                        ll_set(this,i,pAuxTwo);
                        ll_set(this,j,aux);
                    }
                }
                if(order==0)
                {
                    if(pFunc(pAux,pAuxTwo)==-1)
                    {
                        aux=pAux;
                        ll_set(this,i,pAuxTwo);
                        ll_set(this,j,aux);
                    }
                }

            }
        }

    }



    return returnAux;
}

