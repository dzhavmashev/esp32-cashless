// Function : FUN_40167238
// Address  : 0x40167238
// Size     : 105 bytes


undefined4 FUN_40167238(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(*param_1 + 0x2c);
  uVar2 = *(uint *)(iVar1 + 0x10);
  if ((uVar2 & 0xe000) == 0) {
    memw();
    *(uint *)(&DAT_3ff7425c + (uint)*(byte *)(param_1 + 1) * -0x3c) =
         (uint)((uVar2 & 0xf000) == 0x1000) << 4 | 0x20;
  }
  else {
    memw();
    FUN_40147fe4(6,0x40,2,0x3f437191,uVar2 >> 0xc & 0xf,*param_1,iVar1);
    FUN_40147fe4(6,0x2000,2,0x3f437188);
  }
  memw();
  return 0;
}

