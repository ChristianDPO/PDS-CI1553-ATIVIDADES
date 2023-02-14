#ifndef VIEW_SISTEMA_FROTA_HPP
#define VIEW_SISTEMA_FROTA_HPP

#include "ModelSistemaFrota.hpp"
#include "EnumTipoOperacao.hpp" 

namespace frota{
/** Classe com as 'telas' (views) do sistema de frota
 */
class ViewSistemaFrota{

    private:
        ModelSistemaFrota* const modelo;
    
    public:
        ViewSistemaFrota(ModelSistemaFrota* const modelo);
        virtual ~ViewSistemaFrota();

        /**
         * Tela do Menu principal
         * @return EnumTipoOperacao Operacao selcionada pelo usuario
         */
        EnumTipoOperacao menuPrincipal() const;
        /**
         * Imprime na tela os veiculos atuiais do sistema
         */
        void visualizarVeiculos() const;
        /**
         * Imprime na tela os motoristas atuiais do sistema
         */
        void visualizarMotoristas() const;
        /**
         * Tela de cadastrar veiculo
         */
        void cadastroVeiculo();
        /**
         * Tela de cadastrar motorista
         */
        void cadastroMotorista();
        /**
         * Tela para selecionar um motorista, mostrando os seus detalhes e permetindo adicionar/remover seus veiculos
         */
        void selecionaMotorista();
        /**
         * Tela para remover um motorista
         */
        void removeMotorista();
        /**
         * Realiza a operacao especificada, reportando em caso de erro ou sucesso
         * @return void
         */
        void realizaOperacao(EnumTipoOperacao op);

};
}

#endif