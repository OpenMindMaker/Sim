
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author sim
 */
public class ParamTokenizer {

    private final String FromClient;
    private final String delim;
    private ArrayList list;

    /**
     *
     * @param FromClient
     * @param delim
     */
    public ParamTokenizer() {
        this.FromClient = "None";
        this.delim = "None";
        list = new ArrayList(20);
    }

    public ParamTokenizer(String FromClient, String delim) {
        this.FromClient = FromClient;
        this.delim = delim;
        list = new ArrayList(20);
    }

    public ArrayList EnableUse() {
        StringTokenizer st1 = new StringTokenizer(FromClient, delim);
        while (st1.hasMoreTokens()) {
            String temp = st1.nextToken();
            if (st1.equals(delim)) {
                //System.out.println("\n");
            } else {
                //System.out.println(temp);
                list.add(temp);
            }
        }
        return list;
    }
}
