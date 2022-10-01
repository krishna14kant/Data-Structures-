FROM node:lts

# Create app directory
RUN mkdir -p /home/node/app/node_modules && chown -R node:node /home/node/app
WORKDIR /home/node/app

# Install app dependencies
# A wildcard is used to ensure both package.json AND package-lock.json are copied
# where available (npm@5+)
COPY package*.json ./

USER node

RUN npm install
# If you are building your code for production
# RUN npm ci --only=production

# Bundle app source
COPY --chown=node:node . .

EXPOSE 3000

CMD [ "node", "index.js" ]

# docker build -t file-parser .
# Windows: docker run --name file-parser -v C:\\uploads:/home/node/app/uploads file-parser
# Linux: docker run --name file-parser -v /home/fmerino/uploads:/home/node/app/uploads file-parser
