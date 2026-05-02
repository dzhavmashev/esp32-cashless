// Function : FUN_400e0364
// Address  : 0x400e0364
// Size     : 88 bytes


void FUN_400e0364(void)

{
  int iVar1;
  
  FUN_400f01ac(0x3ffc5490,0x1c200,0x800001c,0xffffffff,0xffffffff,0,20000,0x70);
  FUN_400f0780(0x3ffc5490,&PTR_FUN_3f406cd4);
  iVar1 = FUN_400d8244(0x3ffc4034);
  if (iVar1 == 0) {
    FUN_400f0780(0x3ffc5490,"ting...");
    FUN_400f1ab4(5000);
    FUN_400efe2c(0x3ffc53f4);
  }
  FUN_400f0780(0x3ffc5490,"tarting");
  FUN_400d81dc(0x3ffc4034);
  return;
}

