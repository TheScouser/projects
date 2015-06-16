import java.io.IOException;

import org.atmosphere.config.managed.Decoder;
import org.atmosphere.config.managed.Encoder;
import org.codehaus.jackson.map.ObjectMapper;


public final class MessageCodeDecode implements Encoder<ChatMessage, String>, Decoder<String, ChatMessage>{

	   private final ObjectMapper mapper = new ObjectMapper();

	    public ChatMessage decode(final String s){
	        try{
	            return mapper.readValue(s, ChatMessage.class);
	        }catch(IOException e){
	            throw new RuntimeException(e);
	        }
	    }

	    public String encode(final ChatMessage message){
	        try{
	            return mapper.writeValueAsString(message);
	        }catch(IOException e){
	            throw new RuntimeException(e);
	        }
	    }

}
