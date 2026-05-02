// Function : FUN_4016f888
// Address  : 0x4016f888
// Size     : 218 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016f888(char param_1,char param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (int)param_1;
  iVar3 = (int)param_2;
  memw();
  memw();
  DAT_3ffc7e7b = 1;
  memw();
  iVar5 = (int)_DAT_3ffc7e92;
  DAT_3ffca519 = param_1;
  (*(code *)&SUB_4008819c)();
  uVar1 = (*(code *)&SUB_40086ecc)();
  uVar2 = FUN_4016f7a8(iVar4,DAT_3ffca5b9,iVar5);
  if (iVar3 < 4) {
    iVar5 = (int)DAT_3ffca51b;
    if (DAT_3ffca51b != iVar3) {
      FUN_4018eb1c(iVar3);
      memw();
      iVar5 = iVar3;
      DAT_3ffca51b = param_2;
    }
  }
  else {
    FUN_4018eb1c((int)DAT_3ffca51b);
    iVar5 = iVar3;
  }
  (**(code **)(_DAT_3ffc7e64 + 100))(iVar4,uVar2,iVar5);
  FUN_4016a410(iVar4);
  (*(code *)&SUB_40086ee0)(uVar1);
  if (DAT_3ffc7e6c != '\0') {
    if (iVar4 == 0xe) {
      FUN_4016b584(1);
    }
    else {
      FUN_4016b584(0);
    }
  }
  (*(code *)&SUB_400881f8)();
  return;
}

