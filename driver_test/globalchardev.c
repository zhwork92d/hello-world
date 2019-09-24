#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHOUHUI");
#define DEV_NAME "CHARDEV"

static ssize_t GlobalRead(struct file *,char *, size_t,loff_t *);
static ssize_t GlobalWrite(struct file *,const char *, size_t,loff_t *);
static int char_major =3;
static int GlobalData =3;

//init char device file_operations 
struct file_operations globalchar_fops=
{
  .read =GlobalRead,
  .write = GlobalWrite
};

static int __init GlobalChar_init(void){
 int ret;
  ret = register_chrdev(char_major,DEV_NAME,&globalchar_fops);
  if(ret<0)
    printk(KERN_ALERT "global char reg fail !!! \n");
else{
   printk(KERN_ALERT "global char reg success!!!\n");
   printk(KERN_ALERT "ret %d \n",ret);
   char_major = ret;
   printk(KERN_ALERT "Major = %d \n",char_major);
}
return ret;
}

static void __init GlobalChar_exit(void){
   unregister_chrdev(char_major,DEV_NAME);
   return;
}

static ssize_t GlobalRead(struct file *filp,char *buf,size_t len,loff_t *off){
   if (copy_to_user(buf,&GlobalData,sizeof(int))){
       return -EFAULT;
   }
  return sizeof(int);
}

static ssize_t GlobalWrite(struct file *filp,const char *buf,size_t len,loff_t *off){
   if(copy_from_user(&GlobalData,buf,sizeof(int))){
   return -EFAULT;
  }
  return sizeof(int);
}

module_init(GlobalChar_init);
module_exit(GlobalChar_exit);
