// Function : FUN_4013bc9c
// Address  : 0x4013bc9c
// Size     : 249 bytes


int FUN_4013bc9c(int param_1,code *param_2,undefined4 param_3,int param_4,uint param_5,
                undefined4 param_6,undefined1 *param_7)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  
  if ((((param_4 == 1) && (*(int *)(param_1 + 0xa4) != 0)) || (0xfffffff4 < param_5)) ||
     (*(uint *)(param_1 + 4) < param_5 + 0xb)) {
LAB_4013bcb0:
    iVar3 = -0x4080;
  }
  else {
    iVar3 = *(uint *)(param_1 + 4) - param_5;
    *param_7 = 0;
    memw();
    if (param_4 == 0) {
      if (param_2 == (code *)0x0) goto LAB_4013bcb0;
      param_7[1] = 2;
      memw();
      pcVar2 = param_7 + iVar3 + -1;
      for (pcVar5 = param_7 + 2; pcVar5 != pcVar2; pcVar5 = pcVar5 + 1) {
        iVar3 = 100;
        while( true ) {
          memw();
          iVar1 = (*param_2)(param_3,pcVar5,1);
          if (*pcVar5 != '\0') break;
          iVar3 = iVar3 + -1;
          if ((iVar3 == 0) || (iVar1 != 0)) goto LAB_4013bd50;
        }
        if (iVar1 != 0) {
LAB_4013bd50:
          return iVar1 + -0x4480;
        }
      }
    }
    else {
      param_7[1] = 1;
      memw();
      puVar4 = param_7;
      while (param_7 + iVar3 + -3 != puVar4) {
        puVar4[2] = 0xff;
        memw();
        puVar4 = puVar4 + 1;
        memw();
      }
      pcVar2 = param_7 + iVar3 + -1;
      memw();
    }
    *pcVar2 = '\0';
    memw();
    if (param_5 != 0) {
      memw();
      (*(code *)&SUB_4008b3d0)(pcVar2 + 1,param_6,param_5);
    }
    if (param_4 == 0) {
      iVar3 = FUN_4013b510(param_1,param_7,param_7);
    }
    else {
      iVar3 = FUN_4013b574(param_1,param_2,param_3,param_7,param_7);
    }
  }
  return iVar3;
}

