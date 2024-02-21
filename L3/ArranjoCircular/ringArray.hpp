#include <vector>

template <class T>
class RingArray
{
private:
    std ::vector<T> _buffer;
    int _capacidade; // máximo número de itens comportado pelo nosso aranjo circular
    int _tamanho;    //  quantidade de itens que existem atualmente no arranjo circular
    int _head = 0;   // index do elemento mais antigo da lista
    int _tail = 0;   // index do elemento mais recente da lista
public:
    RingArray(int capacidade)
    {
        _capacidade = capacidade;
        _buffer.resize(_capacidade);
        _tamanho = 0;
    } //: Inicializa e aloca o array.

    void push(T item)
    {
        _buffer[_tail] = item;
        _tail = (_tail + 1) % _capacidade;
        if (_tamanho < _capacidade)
        {
            _tamanho++;
        }
        else
        {
            _head = (_head + 1) % _capacidade;
        }
    } //: adiciona um item no arranjo. Caso o arranjo esteja cheio, substitui o item mais antigo adicionado. Dica: usar operador de módulo (%).
    T get(int index)
    {
        int posicao = (_head + index) % _capacidade;
        return _buffer[posicao];
    } //: retorna o item na posição especificada pelo index. O index será um valor maior ou igual a 0 e menor que o tamanho atual do array (para simplificar o problema, não precisa checar essas condicionais).  Lembrando: o index começa a contar a partir do atributo _head, não do index 0 (como fazemos em arranjos convencionais). Dica: usar operador de módulo (%).
    T pop()
    {
        T poped = _buffer[_head];
        _head = (_head + 1) % _capacidade;
        _tamanho--;
        return poped;

    } //: remove o item mais antigo inserido no arranjo. Não precisa checar se o arranjo está vazio.
    void print()
    {
        for (int i = _head; i < _tamanho + _head; i++)
        {
            int pos = (i) % _capacidade;
            std::cout << _buffer[pos] << std::endl;
        }
    } //: imprime todos os elementos presentes no arranjo separados por uma quebra de linha.
    T get_maior()
    {
        T maior = _buffer[_head];
        for (int i = _head; i < _tamanho; i++)
        {
            int pos = (i) % _capacidade;
            if (_buffer[pos] > maior)
            {
                maior = _buffer[pos];
            }
        }
        return maior;
    } //: retorna o maior elemento do arranjo. Não precisa checar se o arranjo está vazio.
    int size()
    {
        return _tamanho;
    } //: retorna o tamanho atual da lista
    bool is_empty()
    {
        return _tamanho == 0;
    } //: retorna se o arranjo está vazio
    bool is_full()
    {
        return _tamanho == _capacidade;
    } //: retorna se o arranjo está cheio
};
