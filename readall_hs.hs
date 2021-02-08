import Text.Printf (printf)
import qualified Data.ByteString as BS

main = printf "length: %d\n" =<< BS.length <$> BS.getContents
