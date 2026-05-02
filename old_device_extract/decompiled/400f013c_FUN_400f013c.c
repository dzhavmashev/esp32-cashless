// Function : FUN_400f013c
// Address  : 0x400f013c
// Size     : 90 bytes


void FUN_400f013c(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  FUN_400f1a68(0x400eff08,"ailed\r\n",0x800,param_1,0x18,param_1 + 0x44,0xffffffff);
  if (*(int *)(param_1 + 0x44) == 0) {
    uVar3 = func_0x40085c04();
    uVar1 = FUN_401847ec("nternal");
    uVar2 = (*(code *)&SUB_4000cff8)((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),1000,0);
    FUN_4012105c("nt_task",uVar2,uVar1,0x71,"\n",*(undefined1 *)(param_1 + 0x10));
  }
  return;
}

