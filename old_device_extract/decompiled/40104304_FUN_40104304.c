// Function : FUN_40104304
// Address  : 0x40104304
// Size     : 82 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40104304(undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x30;
  if ((_DAT_3ffc80e0 >> 0x11 & 1) == 0) {
    uVar2 = 0x20;
  }
  iVar1 = (*(code *)&SUB_4008b3d0)(0x3ffc7ef0,param_1,uVar2);
  *(undefined4 *)(iVar1 + 0x40) = uVar2;
  if (param_3 != '\0') {
    memw();
    FUN_40106520(*(undefined4 *)(iVar1 + 0x1bc),param_1,0x20,param_2,0,0,0x3ffc812a,0x3ffc8124,
                 *(undefined4 *)(iVar1 + 0x1f8),*(undefined4 *)(iVar1 + 0x1f0));
  }
  return;
}

