class Song
  attr_accessor :name, :artist, :genre,:subgenre, :tags
  def initialize(name, artist, genre,subgenre,tags)
    @name   = name
    @artist = artist
    @genre  = genre
    @subgenre  = subgenre
    @tags = Array(tags)
  end

def load_tags tags
  @tags |= tags
  @tags << genre.downcase
  if @subgenre 
    @tags << subgenre.downcase
  end
end
def match(criteria)
   criteria.keys.each do |key|
    if key == :tags
      print criteria[key]

    end

  end
end

end






class Collection
	attr_accessor :songs,:songs_as_strings, :artist_tags

  def initialize(songs,artists)
    @songs = Array.new
    @songs_as_strings = songs.lines.to_a.map { |a| a.chomp}
    @artist_tags = eval(artists.to_s) 
    parse()
    load_songs_tags
  end

def parse
  songs_as_strings.map do |line|
  name, artist, genres, tags = line.split('.').map {|a| a.strip}
  genre, subgenre = genres.split(',').map {|b| b.strip}
  if !tags.nil? 
    tags = tags.split(',').map {|c| c.strip}
  end
    @songs << Song.new(name, artist, genre, subgenre, tags)
  
  end
end

def load_songs_tags
    @artist_tags.map do |artist, tags|
      find(artist: artist).map {|s| s.load_tags tags}
    end
end

def find(criteria)
  @songs.select {|s| s.match(criteria)}
end




end

dictionary={
  'John Coltrane' => %w[saxophone],
  'Bach' => %w[piano polyphony],
}

collection = Collection.new("My Favourite Things.          John Coltrane.      Jazz, Bebop.        popular, cover
Greensleves.                  John Coltrane.      Jazz, Bebop.        popular, cover
Alabama.                      John Coltrane.      Jazz, Avantgarde.   melancholic
Acknowledgement.              John Coltrane.      Jazz, Avantgarde.
Afro Blue.                    John Coltrane.      Jazz.               melancholic
'Round Midnight.              John Coltrane.      Jazz.
My Funny Valentine.           Miles Davis.        Jazz.               popular
Tutu.                         Miles Davis.        Jazz, Fusion.       weird, cool
Miles Runs the Voodoo Down.   Miles Davis.        Jazz, Fusion.       weird
Boplicity.                    Miles Davis.        Jazz, Bebop.
Autumn Leaves.                Bill Evans.         Jazz.               popular
Waltz for Debbie.             Bill Evans.         Jazz.
'Round Midnight.              Thelonious Monk.    Jazz, Bebop.
Ruby, My Dear.                Thelonious Monk.    Jazz.               saxophone
Fur Elise.                    Beethoven.          Classical.          popular
Moonlight Sonata.             Beethoven.          Classical.          popular
Pathetique.                   Beethoven.          Classical.
Toccata e Fuga.               Bach.               Classical, Baroque. popular
Goldberg Variations.          Bach.               Classical, Baroque.
Eine Kleine Nachtmusik.       Mozart.             Classical.          popular, violin
",dictionary)



collection.find tags: 'jazz'
return Array.new(@songs.select{|c| (c.tags & tags).length == tags.length})