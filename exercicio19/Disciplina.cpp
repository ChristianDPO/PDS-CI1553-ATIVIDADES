#include "Disciplina.hpp"
#include "SalaAula.hpp"
#include "ConteudoMinistrado.hpp"
#include "Pessoa.hpp"

#include <iostream>

namespace ufpr{

Disciplina::Disciplina(const std::string& nome)
        : nome{nome}, cargaHoraria{0}, professor{nullptr}, sala{nullptr}, tipo{EnumTipoDisciplina::MANDATORIA} {}

Disciplina::Disciplina(const std::string& nome, SalaAula* const sala)
        : Disciplina{nome} {
    this->setSalaAula(sala);
}

Disciplina::Disciplina(const std::string& nome, SalaAula* const sala, const EnumTipoDisciplina tipo) 
        :nome{nome}, cargaHoraria{0}, professor{nullptr}, sala{nullptr}, tipo{EnumTipoDisciplina::MANDATORIA} {
    this->setSalaAula(sala);
}

Disciplina::Disciplina(const std::string& nome, SalaAula* const sala, const EnumTipoDisciplina tipo, const Ementa& ementa) 
        :nome{nome}, cargaHoraria{0}, professor{nullptr}, sala{nullptr}, tipo{EnumTipoDisciplina::MANDATORIA}, ementa{ementa} {
    this->setSalaAula(sala);
}

Disciplina::Disciplina(const Disciplina& disciplina)
    :nome{disciplina.nome}, cargaHoraria{disciplina.cargaHoraria}, 
    sala{disciplina.sala}, tipo{disciplina.tipo}, ementa{disciplina.ementa}
    {
    
    std::cout << "Chamando Disciplina Construtor de Copia\n";
    
    if(disciplina.professor != nullptr){
        Professor* p1{new Professor{*(disciplina.professor)}};
        this->professor = p1;
    }

    std::list<ConteudoMinistrado*>::const_iterator it;
    for (it = disciplina.conteudos.begin(); it != disciplina.conteudos.end(); ++it){
        this->conteudos.push_back(new ConteudoMinistrado{**(it)});
    }

    std::list<Pessoa*>::const_iterator itP;
    for (itP = disciplina.alunos.begin(); itP != disciplina.alunos.end(); ++itP){
        this->alunos.push_back(new Pessoa{**(itP)});
    }
        
}

Disciplina::Disciplina(Disciplina&& disciplina)
    :nome{disciplina.nome}, cargaHoraria{disciplina.cargaHoraria}, 
    sala{disciplina.sala}, tipo{disciplina.tipo}, ementa{disciplina.ementa},
    conteudos{disciplina.conteudos}, alunos{disciplina.alunos}
{
    
    std::cout << "Chamando Disciplina Move Asignment\n";

    disciplina.professor = nullptr;
    disciplina.sala = nullptr;
    disciplina.conteudos.empty();
    disciplina.alunos.empty();
    
}

Disciplina::~Disciplina() {
    // o setSalaAula vai remover a disciplina da sala de aula antiga, caso ela
    // exista
    this->setSalaAula(nullptr);
    std::list<ConteudoMinistrado*>::iterator it;
    for (it = conteudos.begin(); it != conteudos.end(); it++)
        delete *it;  // liberando a memória de cada conteúdo
}

const std::string& Disciplina::getNome() const { return nome; }

void Disciplina::setNome(const std::string& nome) { this->nome = nome; }

int Disciplina::getCargaHoraria() const { return this->cargaHoraria; }

void Disciplina::setCargaHoraria(const unsigned int carga) {
    this->cargaHoraria = carga;
}

const Professor* Disciplina::getProfessor() const { return this->professor; }

void Disciplina::setProfessor(Professor* const prof) { this->professor = prof; }

void Disciplina::setSalaAula(SalaAula* const sala) {
    if (this->sala !=
        nullptr)  // se já existia uma sala, remover a disciplina dessa sala
        this->sala->disciplinasMinistradas.remove(this);
    this->sala = sala;
    if (this->sala != nullptr)
        this->sala->disciplinasMinistradas.push_back(
            this);  // adicionar a disciplina na nova sala
}

void Disciplina::anularSalaAula() { this->sala = nullptr; }

const SalaAula* Disciplina::getSalaAula() const { return this->sala; }

void Disciplina::imprimirDados(const std::string& cabecalho,
                               const unsigned int cargaTotalCurso) const {
    double pctCurso = (double)this->cargaHoraria / cargaTotalCurso;
    pctCurso = pctCurso * 100;
    std::cout << cabecalho << std::endl;
    std::cout << "Disciplina: " << this->nome << std::endl;
    std::cout << "Carga: " << this->cargaHoraria << std::endl;
    std::cout << "Porcentagem do curso: " << pctCurso << "%" << std::endl;
    std::cout << "Professor: " << this->professor->getNome() << std::endl;
    std::cout << "Alunos:\n\n";
    
    std::list<Pessoa*>::const_iterator itP;
    for (itP = this->alunos.begin(); itP != this->alunos.end(); ++itP){
        std::cout << "Nome: " << (*itP)->getNome() << std::endl;
        std::cout << "CPF: " << (*itP)->getCpf() << std::endl;
    }

    std::cout << "\nCounteudos:\n\n";
    this->imprimirConteudosMinistrados();  

}

void Disciplina::adicionarConteudoMinistrado(
    const std::string& conteudo, const unsigned short cargaHorariaConteudo) {
    this->conteudos.push_back(
        new ConteudoMinistrado{conteudo, cargaHorariaConteudo});
}

void Disciplina::imprimirConteudosMinistrados() const {
    std::list<ConteudoMinistrado*>::const_iterator it;
    for (it = conteudos.begin(); it != conteudos.end(); it++) {
        std::cout << "Id: " << (*it)->getId() << std::endl
                  << "Conteudo: " << (*it)->getDescricao() << std::endl
                  << "Carga: " << (*it)->getCargaHorariaConteudo() << std::endl
                  << std::endl;
    }
}

const std::list<ConteudoMinistrado*>& Disciplina::getConteudos() const {
    return this->conteudos;
}

void Disciplina::adicionarAluno(Pessoa* const aluno) {
    this->alunos.push_back(aluno);
}

void Disciplina::removerAluno(Pessoa* const aluno) {
    this->alunos.remove(aluno);
}

void Disciplina::removerAluno(const unsigned long cpf) {
    std::list<Pessoa*>::iterator it;

    for (it = this->alunos.begin(); it != this->alunos.end(); it++)
        if ((*it)->getCpf().getNumero() == cpf) break;
    if (it != this->alunos.end()) this->alunos.erase(it);
}

const std::list<Pessoa*>& Disciplina::getAlunos()
    const {  // retornamos uma referência para a lista, o que custa mais barato
    return this->alunos;
}

void Disciplina::setEmenta(const Ementa& ementa){
    this->ementa = ementa;
}

const Ementa& Disciplina::getEmenta() const{
    return this->ementa;
}
}