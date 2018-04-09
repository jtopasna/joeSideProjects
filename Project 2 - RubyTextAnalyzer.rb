#!/usr/local/bin/ruby
# NAME: Joe Topasna
# DATE: Feb. 24, 2018
# FILE: RubyTextAnalyzer.rb
# DESC: This text analyzer displays some basic stats about input files. Code starts by reading
#in a file, then processing it. This code uses ruby regexp to process data.
# The code is written in a big loop in case the user wants to analyze an entire folder of text files
# Should be noted that the directories need to be updated in this code to read/analyze text.






#Intro Text
30.times {print "#"}

puts

10.times {print " "}

print "RUBY TEXT ANALYZER"

10.times {print " "}

30.times {print "#"}





#Create stop words array -- Stop Words are words that should not be counted towards stats
stopWordsArray = File.read('stop_words.txt').split("\n")





path = "inaugural_addresses"

d = Dir.new("#{path}")

d.each do |speech|


	if("#{speech}" != "." && "#{speech}" != "..")

				str = ""

				2.times {puts}

				puts "====NOW PRINTING #{speech}==="

				2.times {puts}
				puts "#{path}/#{speech}"


				lines = File.readlines("inaugural_addresses/#{speech}")

				lines_count = lines.size - 1 #first line not included


				text = lines[2..lines.size].join


				puts "Lines = #{lines_count}"


				#number of characters including whitespace

				charArray = text.split("")

				spaceCharCount = charArray.count

				puts "Chars = #{spaceCharCount}"

				#number of chars excluding whitespace


				newString = text.gsub(/\s+/,"").split("")

				puts "Chars (no space) = #{newString.count}"



				#number of words

				numWords = text.split(/\W+/).size

				puts "Words = #{numWords}"



				def count_sentences(string)

					stringCount = string.split(/\.|\?|\!/).count
				    
				    if(stringCount == 0)
				    	
				    	false

					else

						stringCount

				    end

				end

				#number of sentences

				numSentences = count_sentences(text)

				puts "Sentences = #{numSentences}"



				def count_paragraphs(string)

					stringCount = string.split(/\n{2,}|\n{3,}/).count

					 if(stringCount == 0)
				    	
				    	false

					else

						stringCount

				    end

				end



				#number of paragraphs


				puts "Paragraphs = #{count_paragraphs(text)}"


				#number of words per sentence

				puts "Words per Sentence = #{numWords / numSentences}"




				#non-fluff

				counter = 0

				newArray = text.split(/\W+/)

				meaningfulHash = Hash.new

				newArray.each do |word|

					if(!stopWordsArray.include?("#{word.downcase}")) #if a word is meaningful word add to hash
						
						counter = counter + 1

						#IF word not in hash, add to hash and set value to 1
						if(!meaningfulHash.has_key?("#{word.downcase}"))

							meaningfulHash["#{word.downcase}"] = 1

						else

						#else.. increment hash value for that word

							meaningfulHash["#{word.downcase}"] += 1

						end	

					end

				end




				#nofluff = (counter / numWords.size) * 100

				nofluff = (counter.to_f / numWords.to_f) * 100

				puts "Non-fluff = #{nofluff}"


				#fluff

				fluff = 100.0 - nofluff

				puts "Fluff = #{fluff} %"




				supahNew = Hash.new

				supahNew = meaningfulHash.sort_by {|key, value| value}.reverse

				puts "THE TEN MOST COMMON SIGNIFICANT WORDS"

				supahNew[0..9].each do |key, value|

					puts "#{key} (#{value})"

				end




				2.times {puts}

				puts "===ABSTRACT==="

				sentences = text.gsub(/\s+/, ' ').strip.split(/\.|\?|\!/)
				sentences_sorted = sentences.sort_by { |sentence| sentence.length }
				one_third = sentences_sorted.length / 3
				ideal_sentences = sentences_sorted.slice(one_third, one_third + 1)
				ideal_sentences = ideal_sentences.select { |sentence| sentence =~ /was|is|are|were|had|am/ }

				ideal_sentences[0..6].each do |element|

					puts element

		end







	end



end	











