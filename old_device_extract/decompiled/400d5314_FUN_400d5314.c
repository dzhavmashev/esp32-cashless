// Function : FUN_400d5314
// Address  : 0x400d5314
// Size     : 458 bytes


int FUN_400d5314(int param_1,undefined8 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  char *pcVar6;
  int in_a12;
  undefined8 uVar7;
  
  iVar1 = FUN_400d465c(param_1);
  if (iVar1 != 0) {
    return iVar1;
  }
  uVar2 = FUN_40183ca8(param_1);
  if (uVar2 == 0x66) {
    *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) & 0x80 | 6;
    *(undefined1 *)param_2 = 0;
    pcVar6 = "t\t";
  }
  else {
    if (uVar2 < 0x67) {
      if (uVar2 != 0x27) {
        if (uVar2 == 0x5b) {
          *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) & 0x80 | 0x40;
          *(undefined4 *)param_2 = 0;
          *(undefined4 *)((int)param_2 + 4) = 0;
          if ((param_4 & 0xff) == 0) {
            return 5;
          }
          *(undefined1 *)(param_1 + 0x1d) = 0;
          iVar1 = FUN_400d465c(param_1);
          if (iVar1 != 0) {
            return iVar1;
          }
          iVar1 = FUN_400d48d8(param_1,0x5d);
          if (iVar1 != 0) {
            return 0;
          }
          while( true ) {
            iVar1 = FUN_40183ab0(param_2,*(undefined4 *)(param_1 + 0x20));
            if (iVar1 == 0) {
              return 4;
            }
            iVar1 = FUN_400d5314(param_1,iVar1,0,(param_4 & 0xff) - 1);
            if (iVar1 != 0) {
              return iVar1;
            }
            iVar1 = FUN_400d465c(param_1);
            if (iVar1 != 0) {
              return iVar1;
            }
            iVar1 = FUN_400d48d8(param_1,0x5d);
            if (iVar1 != 0) break;
            iVar1 = FUN_400d48d8(param_1,0x2c);
            if (iVar1 == 0) {
              return 3;
            }
          }
          return 0;
        }
        if (uVar2 != 0x22) goto LAB_400d5482;
      }
      FUN_40183b30(param_1);
      iVar1 = FUN_400d4ccc(param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar7 = FUN_400d42ec(param_1);
      bVar4 = 4;
      if (in_a12 != 1) {
        bVar4 = 5;
      }
      *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) & 0x80 | bVar4;
      *param_2 = uVar7;
      return 0;
    }
    if (uVar2 == 0x74) {
      *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) & 0x80 | 6;
      pcVar6 = "\fn\nr\rt\t";
      *(undefined1 *)param_2 = 1;
    }
    else {
      if (uVar2 == 0x7b) {
        *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) & 0x80 | 0x20;
        *(undefined4 *)param_2 = 0;
        *(undefined4 *)((int)param_2 + 4) = 0;
        iVar1 = FUN_400d51d8(param_1,param_2,0,param_4);
        return iVar1;
      }
      if (uVar2 != 0x6e) {
LAB_400d5482:
        iVar1 = FUN_40183ca8(param_1);
        uVar2 = 0;
        while( true ) {
          uVar5 = uVar2 & 0xff;
          if ((9 < (iVar1 - 0x30U & 0xff)) &&
             (iVar3 = (*(code *)&LAB_40183a2b_1)(iVar1), iVar3 == 0)) goto LAB_400d54c8;
          uVar2 = uVar2 + 1;
          if (uVar2 == 0x40) break;
          *(undefined1 *)(param_1 + 0x1d) = 0;
          *(char *)(param_1 + uVar2 + 0x23) = (char)iVar1;
          iVar1 = FUN_40183ca8(param_1);
        }
        uVar5 = 0x3f;
LAB_400d54c8:
        *(undefined1 *)(param_1 + uVar5 + 0x24) = 0;
        iVar1 = FUN_400d3f78(param_1 + 0x24,param_2);
        if (iVar1 != 0) {
          return 0;
        }
        return 3;
      }
      pcVar6 = "PIO ISR null";
    }
  }
  iVar1 = FUN_400d46a0(param_1,pcVar6);
  return iVar1;
}

