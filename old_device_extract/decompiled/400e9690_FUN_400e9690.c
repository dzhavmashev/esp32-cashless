// Function : FUN_400e9690
// Address  : 0x400e9690
// Size     : 94 bytes


void FUN_400e9690(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 local_2c [11];
  
  iVar1 = FUN_400e81d0();
  if (iVar1 != 0) {
    uVar2 = FUN_400e7910(0);
    iVar1 = FUN_4010173c(uVar2,local_2c);
    if (iVar1 == 0) {
      FUN_400f058c(param_1,local_2c[0]);
      return;
    }
    uVar4 = func_0x40085c04();
    uVar2 = FUN_401847ec("face_ip");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),1000,0);
    FUN_4012105c("iled!\r\n",uVar3,uVar2,0x208,"2X:%02X");
  }
  FUN_400f057c(param_1);
  return;
}

