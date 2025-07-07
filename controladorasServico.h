#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

/**
 * @class CntrServicoAutenticacao
 * @brief Implementação concreta da interface de serviço de autenticação.
 *
 * Essa classe fornece a lógica de negócio necessária para autenticar um usuário
 * com base em seu CPF e senha. Pode ser utilizada por controladoras da camada
 * de apresentação para verificar as credenciais dos usuários.
 */
class CntrServicoAutenticacao : public IServicoAutenticacao {
public:
    /**
     * @brief Realiza a autenticação do usuário.
     * @param cpf CPF fornecido pelo usuário.
     * @param senha Senha fornecida pelo usuário.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    virtual bool autenticar(Cpf cpf, Senha senha) override;
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
