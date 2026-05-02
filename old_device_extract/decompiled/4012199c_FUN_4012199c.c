// Function : FUN_4012199c
// Address  : 0x4012199c
// Size     : 218 bytes


/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4012199c(int param_1,undefined4 param_2)

{
  undefined4 unaff_retaddr;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 in_WindowBase;
  undefined1 in_WindowStart;
  undefined1 uVar4;
  undefined1 auStack_20 [32];
  
  _DAT_3ffc6d94 = *(undefined4 *)(param_1 + 0x1c);
  memw();
  uVar4 = 0;
  (*(code *)&SUB_4008b530)(0x3ffc6dac,0xa5,0x464);
  (*(code *)&SUB_400964f8)();
  _DAT_3ffc6da0 = rsr(uVar4);
  _DAT_3ffc6da4 = rsr(in_WindowBase);
  _DAT_3ffc6da8 = rsr(in_WindowStart);
  _DAT_3ffc71c4 = 0x3ffc7200;
  uVar3 = rsr(uVar4);
  wsr(uVar4,uVar3 & 0xfff8f0ff);
  rsync();
  uVar3 = rsr(in_WindowBase);
  wsr(in_WindowStart,1 << 0x20 - (0x20 - (uVar3 & 0x1f)));
  rsync();
  uVar3 = rsr(uVar4);
  wsr(uVar4,uVar3 | 0x40000);
  rsync();
  memw();
  _DAT_3ffc6d98 = auStack_20;
  _DAT_3ffc6d9c = unaff_retaddr;
  FUN_40122b70(param_1);
  iVar1 = FUN_40122a34(param_2);
  if (iVar1 != 0) {
    uVar2 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc0a00,uVar2,0x3ffc0a38,iVar1);
  }
  wsr(uVar4,_DAT_3ffc6da0 & 0xfffbffff);
  rsync();
  wsr(in_WindowBase,_DAT_3ffc6da4);
  rsync();
  wsr(in_WindowStart,_DAT_3ffc6da8);
  rsync();
  wsr(uVar4,_DAT_3ffc6da0);
  rsync();
  return _DAT_3ffc6da4;
}

