import java.util.LinkedList;
import java.util.Queue;

import product.product;

class flat extends product {
    private double area;
    final int type = 1;

    public double getdata() {
        return area;
    }

    flat(String s, int x, double area) {
        super(s, x);
        this.area = area;
    }
}

class stereoscopic extends product {
    final int type = 2;
    private double volume;

    public double getdata() {
        return volume;
    }

    stereoscopic(String s, int x, double v) {
        super(s, x);
        volume = v;
    }
}

final class rectangle extends flat {
    rectangle(String s, int x, double area) {
        super(s, x, area);
    }
}

final class triangle extends flat {
    triangle(String s, int x, double area) {
        super(s, x, area);
    }
}

final class trapezoid extends flat {
    trapezoid(String s, int x, double area) {
        super(s, x, area);
    }
}

final class cylinder extends stereoscopic {
    cylinder(String s, int x, double v) {
        super(s, x, v);
    }
}

final class sphere extends stereoscopic {
    sphere(String s, int x, double v) {
        super(s, x, v);
    }
}

final class cubiod extends stereoscopic {
    cubiod(String s, int x, double v) {
        super(s, x, v);
    }
}

class producer implements Runnable {
    warehouse w;

    producer(warehouse ww) {
        w = ww;
    }

    public void run() {
    }
}

class FlatProducer extends producer {
    FlatProducer(warehouse ww) {
        super(ww);
    }

    public void run() {
        for (int i = 0;; i++) {
            double random = Math.random();
            if (random <= 1.0 / 3.0) {
                w.AddProduct(new triangle(Thread.currentThread().getName(), i, random * 1000 + 1000));// 这里实在丑的遭不住了，学艺不精。
            } else if (random <= 2.0 / 3.0 & random > 1.0 / 3.0) {
                w.AddProduct(new rectangle(Thread.currentThread().getName(), i, random * 1000 + 1000));
            } else {
                w.AddProduct(new trapezoid(Thread.currentThread().getName(), i, random * 1000 + 1000));
            }
            try {
                Thread.sleep((1000 * (int) Math.random() + 1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class ThreeDProducer extends producer {
    ThreeDProducer(warehouse ww) {
        super(ww);
    }

    public void run() {
        for (int i = 0;; i++) {
            double random = Math.random();
            if (random <= 1.0 / 3.0) {
                w.AddProduct(new sphere(Thread.currentThread().getName(), i, random * 1000 + 1000));// 不知道能不能用模板解决重复问题。虽然Java没有。
            } else if (random <= 2.0 / 3.0 & random > 1.0 / 3.0) {
                w.AddProduct(new cylinder(Thread.currentThread().getName(), i, random * 1000 + 1000));
            } else {
                w.AddProduct(new cubiod(Thread.currentThread().getName(), i, random * 1000 + 1000));
            }
            try {
                Thread.sleep((1000 * (int) Math.random() + 1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class consumer implements Runnable {
    warehouse w;

    consumer(warehouse ww) {
        w = ww;
    }

    public void run() {
    }
}

class FlatConsumer extends consumer {
    FlatConsumer(warehouse ww) {
        super(ww);
    }

    public void run() {
        while (true) {
            product p = w.Withdraw2Product();
            if (p != null) {
                p.display();
            }
            try {
                Thread.sleep((1000 * (int) Math.random() + 1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class ThreeDconsumer extends consumer {
    ThreeDconsumer(warehouse ww) {
        super(ww);
    }

    public void run() {
        while (true) {
            product p = w.Withdraw3Product();
            if (p != null) {
                p.display();
            }
            try {
                Thread.sleep((1000 * (int) Math.random() + 1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

}

class warehouse {
    warehouse(double x, double y) {
        tarea = rarea = x;
        tvolume = rvolume = y;
    }

    void display() {
        while (true) {
            System.out.println("" + "Remaining area is " + rarea + " Remaining volume is " + rvolume);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    Queue<flat> fqueue = new LinkedList<flat>();
    Queue<stereoscopic> squeue = new LinkedList<stereoscopic>();
    double tarea, tvolume, rarea, rvolume;

    synchronized void AddProduct(flat p) {
        if (rarea - p.getdata() >= 0) {
            fqueue.add(p);
            rarea -= p.getdata();
            notifyAll();
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    synchronized void AddProduct(stereoscopic p) {
        if (rvolume - p.getdata() >= 0) {
            squeue.add(p);
            rvolume -= p.getdata();
            notifyAll();
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    synchronized product Withdraw2Product() {
        if (fqueue.isEmpty()) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        if (fqueue.peek() == null) {
            return null;
        }
        rarea += fqueue.peek().getdata();
        notifyAll();
        return fqueue.poll();// 这里为了返回基类也没有什么好的办法，为了处理空的情况只好返回null，感觉也不太美观。
    }

    synchronized product Withdraw3Product() {
        if (squeue.isEmpty()) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        if (squeue.peek() == null) {
            return null;
        }
        rvolume += squeue.peek().getdata();
        notifyAll();
        return squeue.poll();
    }
}

class FactoryTest {
    public static void main(String[] args) {
        warehouse w = new warehouse(10000, 10000);
        FlatProducer p = new FlatProducer(w);
        ThreeDProducer p3 = new ThreeDProducer(w);
        FlatConsumer c = new FlatConsumer(w);
        ThreeDconsumer c3 = new ThreeDconsumer(w);
        new Thread(p, "FlatProducer").start();
        new Thread(p3, "ThreeDProducer").start();
        new Thread(c, "FlatConsumer").start();
        new Thread(c3, "ThreeDConsumer").start();
        w.display();
    }
}