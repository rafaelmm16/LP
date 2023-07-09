package fixacaomaps;

public class Pessoas {
    private String nome, profissao, dataNascimento;
    private double cpf;
    
    public String getNome() {
        return nome;
    }

    public String getProfissao() {
        return profissao;
    }

    public String getDataNascimento() {
        return dataNascimento;
    }

    public double getCpf() {
        return cpf;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setProfissao(String profissao) {
        this.profissao = profissao;
    }

    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

    public void setCpf(double cpf) {
        this.cpf = cpf;
    }
    
    //Alterando o construtor da classe
    public Pessoas(String nome, String profissao, String dataNascimento, 
                        double cpf){
        this.nome = nome;
        this.profissao = profissao;
        this.dataNascimento = dataNascimento;
        this.cpf = cpf;   
    }
    
    //Exibindo os dados
    public void mostraDados(){
        System.out.println("Nome: " + this.nome);
        System.out.println("Profissão: " + this.profissao);
        System.out.println("Data de nascimento: " + this.dataNascimento);
        System.out.println("CPF: " + this.cpf);
        
    }
}
