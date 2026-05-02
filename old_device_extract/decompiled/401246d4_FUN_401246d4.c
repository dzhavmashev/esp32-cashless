// Function : FUN_401246d4
// Address  : 0x401246d4
// Size     : 165 bytes


int * FUN_401246d4(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = (int *)(*(code *)&SUB_40094dd8)(1,100);
  if (piVar1 != (int *)0x0) {
    (*(code *)&SUB_4008b3d0)(piVar1 + 0x17,param_1,6);
    (*(code *)&SUB_4008b3d0)(piVar1 + 1,param_2,0x50);
    iVar2 = FUN_40125b38(piVar1);
    if (iVar2 == 0) {
      iVar2 = (*(code *)&SUB_40094dd8)(1,0xfc);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x20) = 1;
        memw();
        uVar3 = FUN_4018511c(piVar1[4]);
        *(undefined4 *)(iVar2 + 0x14) = uVar3;
        memw();
        iVar4 = FUN_401240c8(piVar1,iVar2);
        if (-1 < iVar4) {
          *(undefined4 *)(iVar2 + 8) = 1;
          memw();
          FUN_401245e4(piVar1,iVar2);
          *(undefined4 *)(iVar2 + 8) = 0;
          memw();
          FUN_401245e4(piVar1,iVar2);
          *piVar1 = iVar2;
          goto LAB_40124778;
        }
        (*(code *)&SUB_40094d80)(iVar2);
      }
      (*(code *)&SUB_40094d80)(piVar1[0x15]);
    }
    (*(code *)&SUB_40094d80)(piVar1);
    piVar1 = (int *)0x0;
  }
LAB_40124778:
  memw();
  return piVar1;
}

