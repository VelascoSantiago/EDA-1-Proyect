#include "DLL.h"

static Node* new_node( int x )
{
   Node* n = (Node*) malloc( sizeof( Node ) );
   if( n != NULL ){
      n->datos = x;
      n->next = NULL;
      n->prev = NULL;
   }

   return n;
}

// Función auxiliar.
//
// Elimina el nodo apuntado por |pos|. Esta función es utilizada
// por DLL_Find_if()
//
// Devuelve el nodo a la derecha del nodo recién eliminado.

static Node* erase( DLL* list, Node* pos )
{
    #if 0
   assert(list);
    assert(list->pos);
    Node* left= list->pos->prev;
    Node* right= list->pos->next;
    free(list->pos);
    left->next=right;
    right->prev=left;
    list->pos=right;
    --list->len;
    #endif
}


/**
 * @brief Crea una lista doblemente enlazada
 *
 * @return Una referencia a la nueva lista
 * @post Una lista existente en el heap
 */
DLL* DLL_New()
{
    DLL* list = (DLL*)malloc(sizeof(DLL));
    if(list){
    list->last=NULL;
    list->first=NULL;
    list->cursor=NULL;
    list->len=0;
    }
    return list;
    
}

/**
 * @brief Destruye una lista.
 *
 * @param this Una lista.
 */
void DLL_Delete( DLL** this )
{
    assert (*this);
    if(DLL_Len(*this)>0)
    {
        DLL_Pop_back(*this);
    }
    free (*this);
    *this=NULL;
}

/**
 * @brief Inserta un elemento a la derecha del cursor
 *
 * @param lista Una referencia a la lista de trabajo
 * @param item El elemento a insertar
 *
 * @post Coloca al cursor en el nuevo nodo
 *
 */
void DLL_Insert( DLL* this, int item )
{
    assert(this);
    if(this->cursor==this->first)
    {
        DLL_Push_front(this,item);
    }
    else
    {
        if(this->cursor==this->last)
        {
            DLL_Push_back(this,item);
        }
        else
        {
        Node*n=new_node(item);
        assert(n);
    
        Node* right= this->cursor->next;
        this->cursor->next=n;
        n->next=right;
        right->prev=n;
        n->prev=this->cursor;
        this->cursor=n;
        ++this->len;
        }
    }
    
}

/**
 * @brief Inserta un elemento en el frente de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void DLL_Push_front( DLL* this, int item )
{
    Node*n = new_node(item);
    if(DLL_Len(this)==0)
    {
        this->first=this->last=this->cursor=n;
    }
    else
    {
        n->next= this->first;
        this->first->prev=n;
        this->first=n;
    }
    ++this->len;
}

/**
 * @brief Inserta un elemento en el fondo de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void DLL_Push_back( DLL* this, int item )
{
   Node* n = new_node( item );
   assert( n );

   if( this->first != NULL ){

      this->last->next = n;
      n->prev = this->last;
      this->last = n;
   } else{
      this->first = this->last = this->cursor = n;
   }
   ++this->len;
}

/**
 * @brief Elimina el elemento al frente de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void DLL_Pop_front( DLL* this )
{
    assert (this->len);
    if(this->first!= this->last)
    {
        Node* x = this->first->next;
        free(this->first);
        x->prev = NULL;
        this->first = x;
        --this->len;
    }
    else
    {
        free(this->first);
        this->first= this->last= this->cursor= NULL;
    }
}

/**
 * @brief Elimina el elemento al fondo de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void DLL_Pop_back( DLL* this )
{
   assert( this->len>0 );
   // ERR: no se puede borrar nada de una lista vacía

   if( this->last != this->first ) // también funciona: if( this->len > 1 ){...}
   {
      Node* x = this->last->prev;
      free( this->last );
      x->next = NULL;
      this->last = x;
      --this->len;
   } else{
      free( this->last );
      this->first = this->last = this->cursor = NULL;
      this->len=0;
   }
}

/**
 * @brief Devuelve una copia del valor apuntado por el cursor
 *
 * @param this Una lista
 *
 * @return El valor apuntado por el cursor
 */
int DLL_Cursor_Get( DLL* this )
{
    return (this->cursor->datos);
}

/**
 * @brief Coloca al cursor al inicio de la lista.
 *
 * @param this Una referencia a la lista de trabajo
 */
void DLL_Cursor_front( DLL* this )
{
   this->cursor = this->first;
}

/**
 * @brief Coloca al cursor al final de la lista.
 *
 * @param this Una referencia a la lista de trabajo
 */
void DLL_Cursor_back( DLL* this )
{
    this->cursor=this->last;
}

/**
 * @brief Mueve al cursor al siguiente elemento a la derecha.
 *
 * @param this Una lista.
 */
void DLL_Cursor_next( DLL* this )
{
    assert (this->cursor != NULL);

    Node* right =this->cursor->next;
    this->cursor= right;
}

/**
 * @brief Mueve al cursor al siguiente elemento a la izquierda.
 *
 * @param this Una lista.
 */
void DLL_Cursor_prev( DLL* this )
{
   assert( this->cursor != NULL );

   Node* left = this->cursor->prev;
   this->cursor = left;
}

bool DLL_Cursor_end(DLL* this)
{
    return(this->cursor==NULL);
}

/**
 * @brief Indica si la lista está vacía.
 *
 * @param this Referencia a una lista.
 *
 * @return true si la lista está vacía; false en caso contrario.
 */
bool DLL_IsEmpty( DLL* this )
{
   return this->first == NULL;
}

/**
 * @brief Devuelve el número actual de elementos en la lista.
 *
 * @param this Una lista.
 *
 * @return Devuelve el número actual de elementos en la lista.
 */
size_t DLL_Len( DLL* this )
{
    return this->len;
}

/**
 * @brief Elimina todos los elementos de la lista sin eliminar la lista.
 *
 * @param this Una lista
 */
void DLL_MakeEmpty( DLL* this )
{
    assert(this);
    if(this->len>0)
    {
        while(this->first)
        {
            Node* left=this->first->prev;
            Node* right=this->first->next;
            free(this->first);
            left->next=right;
        }
        this->first=this->last=this->cursor=NULL;
        this->len=0;
    }
}

/**
 * @brief Devuelve una copia del elemento en el frente de la lista
 *
 * @param this Una lista
 *
 * @return La copia del elemento en el frente de la lista
 *
 * @pre La lista NO debe estar vacía
 */
int DLL_Front( DLL* this )
{
   assert( this->first != NULL );
   // ERR: no se puede leer de una lista vacía


   return (this->first->datos);
}

/**
 * @brief Devuelve una copia del elemento en la parte trasera de la lista.
 *
 * @param this Una lista.
 *
 * @return La copia del elemento en la parte trasera de la lista.
 *
 * @pre La lista NO debe estar vacía
 */
int DLL_Back( DLL* this )
{
    assert (this);
    return this->last->datos;
    
}

/**
 * @brief Elimina el elemento apuntado por el cursor.
 *
 * @param this Una lista.
 *
 */
void DLL_Erase( DLL* this )
{
    assert(this);
    if(this->cursor==this->first)
    {
        DLL_Pop_front(this);
        this->cursor=this->first;
    }
    else
    {
        if(this->cursor==this->last)
        {
            DLL_Pop_back(this);
            this->cursor=this->last;
        }
        else
        {
            Node* left= this->cursor->prev;
            Node* right= this->cursor->next;
            free(this->cursor);
            left->next=right;
            right->prev=left;
            this->cursor=right;
            --this->len;
        }   
    }
}

/**
 * @brief Elimina el primer nodo que coincida con la llave.
 *
 * @param this Una lista
 * @param key  Valor buscado
 *
 */
 #if 1
void DLL_Remove( DLL* this, int key )
{
    assert(this);
    Node* it= this->first;
    while(it!=NULL)
    {
        if(it->datos==key)
        {
            if (it==this->first)
            {
                DLL_Pop_front(this);
            }
            else
            {
                if(it==this->last)
                {
                    DLL_Pop_back(this);
                }
                else
                {
                    Node*left=it->prev;
                    Node*right= it->next;
                    free(it);
                    left->next=right;
                    right->prev=left;
                    it=right;
                }
            }    
        }
        it=it->next;
    }
    
}
#endif

/**
 * @brief Busca un valor en la lista. Si lo encuentra coloca ahí al cursor.
 *
 * @param this Una lista.
 * @param key El valor que se está buscando.
 *
 * @post Si se encontró una coincidencia coloca al cursor en ese nodo; en caso contrario el cursor es NULL.
 *
 * @code
 * if( DLL_Find( list, x ) )
 * {
 *    y = DLL_Cursor_Get( list );
 *
 *    // ...
 * }
 * @endcode
 */
bool DLL_Find( DLL* this, int key )
{
   for( this->cursor = this->first;
        this->cursor != NULL;
        this->cursor = this->cursor->next )
   {
      if( this->cursor->datos == key )
      {
         return true;
      }
   }
   return false;
}

/**
 * @brief Imprime la estructura de la lista. Es para uso de depuración, no es de uso general.
 *
 * @param this Una lista.
 */
void DLL_PrintStructure( DLL* this )
{
   if( DLL_IsEmpty( this ) )
   {
      fprintf( stderr, "Empty list. Nothing to show.\n" );
   }
   else
   {
      fprintf( stderr, "\nNil->" );

      // usando un for en lugar de while (mi preferido):
      for( Node* it = this->first; it != NULL; it = it->next )
      {
         fprintf( stderr, "(%d)->", it->datos );
      }
      fprintf( stderr, "Nil\n" );
   }
}


//----------------------------------------------------------------------
//                       Avanzadas:
//----------------------------------------------------------------------

/**
 * @brief Recorre la lista y hace algo con cada uno de sus elementos
 *
 * @param lista Una lista
 * @param p_fn Función que procesa cada elemento de la lista
 */
void DLL_For_each( DLL* this, void (*p_fn)( int item ) )
{
   for( Node* it = this->first; it != NULL; it = it->next )
   {
      p_fn( it->datos );
   }
}

/**
 * @brief Busca si algún valor en la lista cumple con la función predicado
 *
 * @param this Una lista
 * @param p_fn Función predicado. El elemento |y| es proporcionado por el argumento |key|, mientras que el valor |x| se obtiene de la lista. Por ejemplo, si la función quiere saber si el valor de la lista es menor que el valor del usuario (list_val < user_val), entonces la función podría ser: less_than( list_val, user_val), la cual se lee en conjunto: "Si el valor de la lista |list_val| es menor que el valor del usuario |user_val|, entonces devuelve verdadero; en caso contrario devuelve falso"
 * @param key El valor contra el que se está realizando la comparación.
 *
 * @return Un apuntador al nodo donde se haya encontrado la primer coincidencia. Devuelve NULL en caso de no haber encontrado ninguna
 */
Node* DLL_Find_if( DLL* this, bool (*cmp)( int, int ), int key )
{
   assert( DLL_IsEmpty( this ) == false );
   // ERR: no se puede buscar nada en una lista vacía

   Node* it = this->first;
   // |it| es la abreviación de "iterator", o  en español, "iterador"

   while( it != NULL ){

      if( cmp( it->datos, key ) == true ) break;

      it = it->next;
   }

   return it;
}


/**
 * @brief Elimina todos los elementos que den positivo a la función predicado.
 *
 * @param this Una lista.
 * @param cmp Función predicado. El elemento |y| es proporcionado por el argumento |key|, mientras que el valor |x| se obtiene de la lista. Por ejemplo, si la función quiere saber si el valor de la lista es menor que el valor del usuario (list_val < user_val), entonces la función podría ser: less_than( list_val, user_val), la cual se lee en conjunto: "Si el valor de la lista |list_val| es menor que el valor del usuario |user_val|, devuelve verdadero".
 * @param key El valor contra el que se está comparando.
 * @return El número de elementos encontrados y borrados.
 */
size_t DLL_Remove_if( DLL* this, bool (*cmp)( int x, int y ), int key )
{
   assert( DLL_IsEmpty( this ) == false );
   // ERR: no se puede eliminar nada de una lista vacía

   Node* it = this->first;
   // |it| es la abreviación de "iterator", o  en español, "iterador"

   size_t elems = 0;

   while( it != NULL ){

      if( cmp( it->datos, key ) == true )
      {
         erase( this, it );
         ++elems;
      }

      it = it->next;
   }

   return elems;
}

#if 1
DLL* DLL_Concat ( const DLL*first, const DLL* second )
{
    DLL* list= DLL_New();
    for (Node*it= first->first; it!=NULL; it=it->next)
    {
        DLL_Push_back(list, it->datos);
    }
    for (Node*it= second->first; it!=NULL; it=it->next)
    {
        DLL_Push_back(list, it->datos);
    }
    return list;
}
#endif