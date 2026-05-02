// Function : FUN_400dd978
// Address  : 0x400dd978
// Size     : 146 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400dd978(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  undefined4 local_90;
  undefined1 auStack_8c [100];
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uVar2 = rsr(in_PRID);
  FUN_400f06a4(0x3ffc5490,"f KGS)\n",uVar2 >> 0xd & 1);
  while (memw(), *(char *)(param_1 + 0x3c) != '\0') {
    iVar1 = func_0x4008fecc(*(undefined4 *)(param_1 + 0x34),&local_90,100);
    if (iVar1 == 1) {
      FUN_400dd958(param_1);
      FUN_400e66d0(*(undefined4 *)(param_1 + 0x24),local_90);
      FUN_400dd968(param_1);
      func_0x4008c100(param_1 + 0x3e,auStack_8c,99);
      memw();
      *(undefined4 *)(param_1 + 0xa4) = uStack_28;
      *(undefined1 *)(param_1 + 0xa1) = 0;
      memw();
      *(undefined1 *)(param_1 + 0x3d) = 1;
    }
  }
  FUN_400f0780(0x3ffc5490,"ore %d\n");
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

