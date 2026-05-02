// Function : FUN_401130a8
// Address  : 0x401130a8
// Size     : 289 bytes


undefined1 FUN_401130a8(int param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x84f,"lid pcb","lid pcb");
  }
  iVar5 = *(int *)(param_1 + 0x98);
  uVar2 = 0;
  if (iVar5 != 0) {
    if (*(char *)(param_1 + 0xce) != -1) {
      *(char *)(param_1 + 0xce) = *(char *)(param_1 + 0xce) + '\x01';
      memw();
    }
    memw();
    uVar3 = FUN_40185290(*(undefined2 *)(*(int *)(iVar5 + 0xc) + 0xc));
    uVar7 = 0;
    if (((uVar3 & 1) != 0) && (*(short *)(iVar5 + 8) == 0)) {
      uVar7 = 1;
    }
    iVar4 = FUN_401102e0(param_1,uVar7 ^ 1,*(undefined4 *)(*(int *)(iVar5 + 0xc) + 4));
    uVar2 = 0xff;
    if (iVar4 != 0) {
      iVar6 = *(int *)(iVar4 + 4);
      if (uVar7 == 0) {
        FUN_4010bfb8(*(int *)(iVar5 + 4),iVar6 + 0x14,1,
                     *(short *)(*(int *)(iVar5 + 4) + 8) - *(short *)(iVar5 + 8));
      }
      else {
        uVar1 = *(ushort *)(iVar6 + 0xc);
        uVar3 = FUN_40185290(0x11);
        uVar3 = ((int)(short)(uVar1 & 0xc0ff) | uVar3) & 0xffff;
        *(char *)(iVar6 + 0xc) = (char)uVar3;
        *(char *)(iVar6 + 0xd) = (char)(uVar3 >> 8);
        memw();
      }
      memw();
      iVar5 = FUN_40109eec(*(undefined4 *)(*(int *)(iVar5 + 0xc) + 4));
      if (*(int *)(param_1 + 0x7c) - (iVar5 + 1) < 0) {
        *(int *)(param_1 + 0x7c) = iVar5 + 1;
      }
      memw();
      FUN_40110330(iVar4);
      uVar2 = FUN_40110224(param_1,iVar4,param_1,param_1 + 0x18);
    }
  }
  return uVar2;
}

