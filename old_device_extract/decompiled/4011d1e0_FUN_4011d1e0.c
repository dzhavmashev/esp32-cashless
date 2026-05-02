// Function : FUN_4011d1e0
// Address  : 0x4011d1e0
// Size     : 201 bytes


void FUN_4011d1e0(uint *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined1 uStack_2d;
  char *pcStack_2c;
  int iStack_28;
  int iStack_24;
  
  if ((param_1[0xd] & 8) == 0) {
    (*(code *)&SUB_40094c54)("rgument",0x374,"delconn","unction");
  }
  if (param_1[4] != 0) {
    while (iVar2 = FUN_4011af34(param_1 + 4,&pcStack_2c), iVar2 != -1) {
      if (pcStack_2c != "_msg") {
        if ((*param_1 & 0xf0) == 0x10) {
          iVar2 = FUN_4011cfd8(pcStack_2c,&iStack_28);
          if (iVar2 == 0) {
            FUN_4010bb10(pcStack_2c);
          }
        }
        else {
          FUN_4011da08();
        }
      }
    }
    FUN_4011af6c(param_1 + 4);
    param_1[4] = 0;
    memw();
  }
  if (param_1[5] != 0) {
    while (iVar2 = FUN_4011af34(param_1 + 5,&pcStack_2c), iVar2 != -1) {
      if ((pcStack_2c != "_msg") &&
         (iVar2 = FUN_4011cfd8(pcStack_2c,&uStack_2d), pcVar1 = pcStack_2c, iVar2 == 0)) {
        pcStack_2c[0x34] = pcStack_2c[0x34] | 8;
        memw();
        memw();
        FUN_4011d1e0(pcStack_2c);
        if (*(int *)(pcVar1 + 8) != 0) {
          memw();
          iStack_28 = iVar2;
          iStack_24 = *(int *)(pcVar1 + 8);
          FUN_40109e54(&DAT_4011c9d4,&iStack_28);
          pcVar1[8] = '\0';
          pcVar1[9] = '\0';
          pcVar1[10] = '\0';
          pcVar1[0xb] = '\0';
        }
        memw();
        FUN_4011d190(pcVar1);
      }
    }
    FUN_4011af6c(param_1 + 5);
    param_1[5] = 0;
    memw();
  }
  return;
}

