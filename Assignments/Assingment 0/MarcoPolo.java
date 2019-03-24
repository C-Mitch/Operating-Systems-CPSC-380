class MarcoPolo implements Runnable {

  int option;
  Thread t;

  public MarcoPolo(int option) {
    super();
    this.option = option;
  }

  public void start() {
      if (t == null) {
         t = new Thread (this, "test");
         t.start();
      }
  }

  public void run() {
    if(option == 0) {
      marco();
    }

    else {
      polo();
    }
  }

  private void marco() {
    try {
      for(int i = 0; i < 10; ++i){
        System.out.println("Marco");
        Thread.sleep(50);
      }
    }
    catch (InterruptedException e) {
      System.out.println("Thread interrupted");
    }
  }

  private void polo() {
    try {
      for(int i = 0; i < 10; ++i){
        System.out.println("Polo");
        Thread.sleep(50);
      }
    }
    catch (InterruptedException e) {
      System.out.println("Thread interrupted");
    }
  }
}

class Test {
  public static void main(String[] args) {
    Thread t1 = new Thread(new MarcoPolo(0), "t1");
    t1.start();
    Thread t2 = new Thread(new MarcoPolo(1), "t2");
    t2.start();

    try {
      t1.join();
      t2.join();
    }
    catch(InterruptedException e) {
      System.out.println("Error");
    }

    System.out.println("That's all folks!");
  }
}
