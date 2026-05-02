// Function : FUN_401501f8
// Address  : 0x401501f8
// Size     : 198 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401501f8(uint param_1,ushort *param_2,ushort param_3,char param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  param_1 = param_1 & 0xff;
  uVar3 = (uint)param_3;
  uVar1 = 1;
  if (param_1 < 0xb) {
    iVar4 = param_1 + 8;
    if ((*(char *)(param_1 + 0x3ffc8844) == '\0') && (*(int *)(iVar4 * 4 + 0x3ffc87f8) != 0)) {
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xb0))();
      *(undefined4 *)(iVar4 * 4 + 0x3ffc87f8) = 0;
    }
    if (param_2 == (ushort *)0x0 && uVar3 == 0) {
      *(undefined4 *)(iVar4 * 4 + 0x3ffc87f8) = 0;
      memw();
      return 0;
    }
    *(char *)(param_1 + 0x3ffc8844) = param_4;
    memw();
    if (param_4 != '\0') {
      *(ushort **)(iVar4 * 4 + 0x3ffc87f8) = param_2;
      *param_2 = param_3;
      memw();
      memw();
      return 0;
    }
    memw();
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x16c))(uVar3 + 2);
    *(int *)(iVar4 * 4 + 0x3ffc87f8) = iVar2;
    if (iVar2 == 0) {
      memw();
      FUN_40147fe4(1,2,2,0x3f436809);
      return 1;
    }
    (*(code *)&SUB_4008b3d0)(iVar2 + 2,param_2,uVar3);
    **(ushort **)(iVar4 * 4 + 0x3ffc87f8) = param_3;
    memw();
    uVar1 = 0;
  }
  memw();
  return uVar1;
}

