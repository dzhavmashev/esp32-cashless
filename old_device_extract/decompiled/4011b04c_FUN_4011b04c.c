// Function : FUN_4011b04c
// Address  : 0x4011b04c
// Size     : 104 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_4011b04c(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_4010af90(4);
  if (piVar1 == (int *)0x0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"t empty","mutex\n\n",uVar2,"t empty");
  }
  else {
    iVar3 = (*(code *)&SUB_4008f990)(1,0,3);
    *piVar1 = iVar3;
    if (iVar3 == 0) {
      memw();
      (*(code *)&SUB_40094d80)(piVar1);
      uVar2 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"t empty","mutex\n\n",uVar2,"t empty");
      piVar1 = (int *)0x0;
    }
    else {
      FUN_400fc864(_DAT_3ffc6514,piVar1);
    }
  }
  return piVar1;
}

