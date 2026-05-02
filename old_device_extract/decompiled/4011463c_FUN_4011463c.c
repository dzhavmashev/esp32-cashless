// Function : FUN_4011463c
// Address  : 0x4011463c
// Size     : 356 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_4011463c(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char extraout_a3;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char cVar9;
  ushort auStack_22 [17];
  
  iVar6 = *(int *)(param_1 + 200);
  FUN_4018541c(iVar6,3);
  iVar2 = FUN_40114430(param_1,iVar6,3,auStack_22);
  if (iVar2 == 0) {
    uVar1 = 0xff;
  }
  else {
    iVar8 = *(int *)(iVar2 + 4);
    iVar5 = iVar8 + 0xf0;
    uVar3 = FUN_401142d4(auStack_22[0],iVar5,0x39,2);
    auStack_22[0] = (ushort)uVar3;
    memw();
    memw();
    uVar3 = FUN_40114298(uVar3,iVar5,0x240);
    auStack_22[0] = (ushort)uVar3;
    memw();
    memw();
    uVar3 = FUN_401142d4(uVar3,iVar5,0x32,4);
    auStack_22[0] = (ushort)uVar3;
    memw();
    memw();
    uVar4 = FUN_40109eec(*(undefined4 *)(iVar6 + 0x3c));
    uVar3 = FUN_40114328(uVar3,iVar5,uVar4);
    auStack_22[0] = (ushort)uVar3;
    memw();
    memw();
    auStack_22[0] = FUN_401142d4(uVar3,iVar5,0x37,5);
    memw();
    uVar7 = (uint)auStack_22[0];
    cVar9 = 'a';
    if (0x7f < uVar7) {
      memw();
      FUN_40114310();
      cVar9 = extraout_a3;
    }
    *(char *)(iVar5 + uVar7) = cVar9;
    auStack_22[0] = (ushort)(uVar7 + 1);
    memw();
    memw();
    uVar3 = FUN_40114568(uVar7 + 1 & 0xffff,iVar5,param_1);
    auStack_22[0] = (ushort)uVar3;
    memw();
    memw();
    uVar3 = FUN_401145e4(param_1,iVar8,uVar3);
    auStack_22[0] = (ushort)uVar3;
    memw();
    memw();
    FUN_40114068(uVar3,iVar5,iVar2);
    uVar1 = FUN_40113b68(_DAT_3ffc6380,iVar2,"dr_aton",0x43,param_1);
    FUN_4010bb10(iVar2);
  }
  if (*(char *)(iVar6 + 6) != -1) {
    *(char *)(iVar6 + 6) = *(char *)(iVar6 + 6) + '\x01';
    memw();
  }
  uVar7 = 10000;
  if (*(byte *)(iVar6 + 6) < 10) {
    uVar7 = (uint)*(byte *)(iVar6 + 6) * 1000 & 0xffff;
  }
  *(short *)(iVar6 + 10) = (short)((uVar7 + 499) / 500);
  memw();
  if (*(char *)(iVar6 + 8) == '\0') {
    memw();
    FUN_40113258(500,&DAT_40115654,param_1);
    *(undefined1 *)(iVar6 + 8) = 1;
    memw();
  }
  memw();
  return uVar1;
}

