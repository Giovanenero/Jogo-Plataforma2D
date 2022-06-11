#pragma once

#include "AnimacaoEstatica.h"
#include "Entidade.h"

//class Caixa;

namespace Entidade {
	namespace Obstaculo {
		class Obstaculo : public Entidade
		{
		protected:
			ElementoGrafico::AnimacaoEstatica* pAnimacaoEstatica;
		public:
			Obstaculo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id);
			~Obstaculo();

			void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);

			void renderizar();
			virtual void inicializacao() = 0;
			virtual void atualizar() = 0;

			const bool podeRemover() const { return false; }

			void atualizar(const float tempo) {
				if (getID() != Ids::Ids::plataforma) {
					velocidade.y += GRAVIDADE * tempo;
					posicao.y += velocidade.y * tempo;
				}
				atualizar();
			}
			void atualizarImagem(const float tempo) { }
		};
	} //namespace Obstaculo
} //namespace Entidade

