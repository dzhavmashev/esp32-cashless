// Function : FUN_40114954
// Address  : 0x40114954
// Size     : 325 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40114954(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort auStack_22 [17];
  
  iVar3 = *(int *)(param_1 + 200);
  *(undefined4 *)(iVar3 + 0x3c) = 0;
  memw();
  FUN_4018541c(iVar3,6);
  iVar1 = FUN_40114430(param_1,iVar3,1,auStack_22);
  if (iVar1 != 0) {
    iVar5 = *(int *)(iVar1 + 4);
    iVar4 = iVar5 + 0xf0;
    uVar2 = FUN_401142d4(auStack_22[0],iVar4,0x39,2);
    auStack_22[0] = (ushort)uVar2;
    memw();
    memw();
    uVar2 = FUN_40114298(uVar2,iVar4,*(undefined2 *)(param_1 + 0xe0));
    auStack_22[0] = (ushort)uVar2;
    memw();
    memw();
    uVar2 = FUN_40114568(uVar2,iVar4,param_1);
    auStack_22[0] = (ushort)uVar2;
    memw();
    memw();
    uVar2 = FUN_401145e4(param_1,iVar5,uVar2);
    auStack_22[0] = (ushort)uVar2;
    memw();
    memw();
    auStack_22[0] = FUN_401142d4(uVar2,iVar4,0x37,5);
    memw();
    uVar6 = (uint)auStack_22[0];
    if (0x7f < uVar6) {
      memw();
      FUN_40114310();
    }
    *(char *)(iVar4 + uVar6) = 'a';
    auStack_22[0] = (ushort)(uVar6 + 1);
    memw();
    memw();
    FUN_40114068(uVar6 + 1 & 0xffff,iVar4,iVar1);
    FUN_4011397c(_DAT_3ffc6380,iVar1,"dr_aton",0x43,param_1,&DAT_3f411ef4);
    FUN_4010bb10(iVar1);
  }
  if (*(char *)(iVar3 + 6) != -1) {
    *(char *)(iVar3 + 6) = *(char *)(iVar3 + 6) + '\x01';
    memw();
  }
  uVar6 = 4000;
  if (*(byte *)(iVar3 + 6) < 5) {
    uVar6 = (1 << 0x20 - (0x20 - (*(byte *)(iVar3 + 6) & 0x1f))) * 0xfa & 0xffff;
  }
  *(short *)(iVar3 + 10) = (short)((uVar6 + 499) / 500);
  memw();
  if (*(char *)(iVar3 + 8) == '\0') {
    memw();
    FUN_40113258(500,&DAT_40115654,param_1);
    *(undefined1 *)(iVar3 + 8) = 1;
    memw();
  }
  memw();
  return 0;
}

