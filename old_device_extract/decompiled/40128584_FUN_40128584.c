// Function : FUN_40128584
// Address  : 0x40128584
// Size     : 156 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40128584(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined1 auStack_64 [64];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (0x21 < param_3) goto LAB_401285b5;
  do {
    iVar1 = -1;
    while( true ) {
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return iVar1;
      }
      memw();
      param_1 = (*(code *)&SUB_40082ec4)();
LAB_401285b5:
      iVar1 = *(int *)(param_1 + 0x48);
      if (((iVar1 == 0) || (*(int *)(param_1 + 0x38) == 0)) || (*(int *)(iVar1 + 0x20) == 0)) break;
      if (*(int *)(iVar1 + 0x40) == 0) {
        if ((*(int *)(iVar1 + 0x2c) == 0) || (*(int *)(iVar1 + 0x24) == 0)) break;
        memw();
        iVar1 = FUN_401260fc(param_1,param_2);
      }
      else {
        if ((*(int *)(iVar1 + 0x30) == 0) || (*(int *)(iVar1 + 0x28) == 0)) break;
        memw();
        iVar1 = FUN_40126194(param_1,param_2);
      }
      if (iVar1 != 0) break;
      iVar1 = (*(code *)&SUB_4008b33c)(auStack_64,param_2 + 2,0x20);
      iVar1 = -(uint)(iVar1 != 0);
    }
  } while( true );
}

