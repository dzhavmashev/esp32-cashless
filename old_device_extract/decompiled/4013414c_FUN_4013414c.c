// Function : FUN_4013414c
// Address  : 0x4013414c
// Size     : 211 bytes


int FUN_4013414c(int *param_1,undefined4 param_2,undefined1 *param_3,int *param_4,undefined4 param_5
                ,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  memw();
  iVar1 = FUN_40134030(param_1,param_2,param_5,param_6);
  if (iVar1 == 0) {
    memw();
    iVar2 = FUN_401317d8(param_1 + 1);
    memw();
    iVar3 = FUN_401317d8(param_1 + 4);
    iVar4 = FUN_401317d8(param_1 + 10);
    memw();
    iVar1 = FUN_40131900(param_1 + 1,param_3 + 2,iVar2);
    if (iVar1 == 0) {
      puVar5 = param_3 + 2 + iVar2;
      *param_3 = (char)((uint)iVar2 >> 8);
      param_3[1] = (char)iVar2;
      memw();
      memw();
      iVar1 = FUN_40131900(param_1 + 4,puVar5 + 2,iVar3);
      if (iVar1 == 0) {
        puVar6 = puVar5 + 2 + iVar3;
        *puVar5 = (char)((uint)iVar3 >> 8);
        puVar5[1] = (char)iVar3;
        memw();
        memw();
        iVar1 = FUN_40131900(param_1 + 10,puVar6 + 2,iVar4);
        if (iVar1 == 0) {
          puVar6[1] = (char)iVar4;
          memw();
          *puVar6 = (char)((uint)iVar4 >> 8);
          memw();
          *param_4 = (int)(puVar6 + 2 + (iVar4 - (int)param_3));
          *param_1 = iVar2;
        }
      }
    }
  }
  if ((iVar1 != 0) && (-0x80 < iVar1)) {
    iVar1 = iVar1 + -0x3180;
  }
  memw();
  return iVar1;
}

