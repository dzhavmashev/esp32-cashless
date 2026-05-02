// Function : FUN_400d4e24
// Address  : 0x400d4e24
// Size     : 316 bytes


int FUN_400d4e24(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  int in_a12;
  
  iVar4 = 5;
  if ((param_4 & 0xff) != 0) {
    *(undefined1 *)((int)param_1 + 0x1d) = 0;
    iVar4 = FUN_400d45e4(param_1);
    if ((iVar4 == 0) && (iVar1 = FUN_400d48b8(param_1,0x7d), iVar1 == 0)) {
      while( true ) {
        FUN_40183b30(param_1);
        iVar4 = (*(code *)&LAB_40183c7b_1)(param_1);
        if ((iVar4 != 0x27) && (iVar4 != 0x22)) break;
        iVar4 = FUN_400d4be8(param_1);
        if (iVar4 != 0) {
          return iVar4;
        }
LAB_400d4e84:
        iVar4 = FUN_400d45e4(param_1);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = FUN_400d48b8(param_1,0x3a);
        if (iVar4 == 0) goto LAB_400d4ea4;
        *(undefined1 *)(param_1[1] + param_1[2]) = 0;
        iVar4 = FUN_400d431c(param_2,param_1[1]);
        if (iVar4 == 0) {
          uVar2 = FUN_400d42ec(param_1);
          iVar4 = FUN_40183ab0(param_2,param_1[8]);
          if (iVar4 == 0) goto LAB_400d4ed1;
          bVar3 = *(byte *)(iVar4 + 8) | 0x80;
          if (in_a12 == 1) {
            bVar3 = *(byte *)(iVar4 + 8) & 0x7f;
          }
          *(byte *)(iVar4 + 8) = bVar3;
          *(undefined4 *)(iVar4 + 0xc) = uVar2;
        }
        in_a12 = 0;
        iVar4 = FUN_400d4f60(param_1,iVar4,0,(param_4 & 0xff) - 1);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = FUN_400d45e4(param_1);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = FUN_400d48b8(param_1,0x7d);
        if (iVar4 != 0) {
          return 0;
        }
        iVar4 = FUN_400d48b8(param_1,0x2c);
        if (iVar4 == 0) goto LAB_400d4ea4;
        iVar4 = FUN_400d45e4(param_1);
        if (iVar4 != 0) {
          return iVar4;
        }
      }
      uVar2 = (*(code *)&LAB_40183c7b_1)(param_1);
      iVar4 = FUN_400d4e04();
      if (iVar4 == 0) {
LAB_400d4ea4:
        iVar4 = 3;
      }
      else {
        do {
          *(undefined1 *)((int)param_1 + 0x1d) = 0;
          (*(code *)&LAB_40183b4f_1)(param_1,uVar2);
          uVar2 = (*(code *)&LAB_40183c7b_1)(param_1);
          iVar4 = FUN_400d4e04();
        } while (iVar4 != 0);
        if (*(char *)(*param_1 + 0x10) == '\0') goto LAB_400d4e84;
LAB_400d4ed1:
        iVar4 = 4;
      }
    }
  }
  return iVar4;
}

