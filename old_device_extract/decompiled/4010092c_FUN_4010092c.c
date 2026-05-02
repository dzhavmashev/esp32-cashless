// Function : FUN_4010092c
// Address  : 0x4010092c
// Size     : 84 bytes


undefined4 FUN_4010092c(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar4 = *(int *)(param_1 + 0xc);
  uVar6 = *(undefined4 *)(param_1 + 0x10);
  uVar1 = 0x102;
  if (iVar4 != 0) {
    uVar2 = (*(code *)&SUB_4008c01c)(uVar6);
    uVar1 = 0x5001;
    if (uVar2 < 0x21) {
      iVar5 = *(int *)(iVar4 + 0x10);
      uVar1 = 0x5002;
      if (iVar5 != 0) {
        if (*(int *)(iVar4 + 0x4c) != 0) {
          (*(code *)&SUB_40094d80)();
        }
        iVar3 = (*(code *)&SUB_4008bfa0)(uVar6);
        *(int *)(iVar4 + 0x4c) = iVar3;
        if (iVar3 == 0) {
          *(char **)(iVar5 + 0xdc) = "D (%x)\n";
          uVar1 = 0x101;
        }
        else {
          *(int *)(iVar5 + 0xdc) = iVar3;
          uVar1 = 0;
          memw();
        }
      }
    }
  }
  memw();
  return uVar1;
}

