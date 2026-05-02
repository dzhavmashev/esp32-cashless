// Function : FUN_400d75e4
// Address  : 0x400d75e4
// Size     : 425 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d75e4(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined1 auStack_58 [20];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
    param_3 = (int *)*param_3;
  }
  FUN_400f06a4(0x3ffc5490,"t Error",param_2,param_3);
  if (param_2 == (int *)0x2) {
    FUN_400f0780(0x3ffc5490,"d (%s)\n");
    if (*param_1 == 4) goto LAB_400d7622;
    FUN_400d7378(auStack_78,0x200,0);
    uVar1 = FUN_400d4db0(auStack_58,"offline status",auStack_70);
    FUN_400d6da8("ssfully",uVar1);
    FUN_400e6d7c(auStack_44,param_1[7]);
    uVar1 = FUN_400d4db0(auStack_58,"",auStack_70);
    FUN_40183db8(auStack_44,uVar1,auStack_70);
    FUN_400f0a50(auStack_44);
    uVar1 = FUN_400d4db0(auStack_58,"loading firmware",auStack_70);
    FUN_400d6da8("version",uVar1);
    iVar2 = (*(code *)&LAB_40183e8b_1)(param_1[2]);
    pcVar3 = "g state";
    if (iVar2 != 1) {
      pcVar3 = "te";
    }
    uVar1 = FUN_400d4db0(auStack_58,"eviceId",auStack_70);
    FUN_400d6da8(pcVar3,uVar1);
    FUN_400f0be8(auStack_34,&DAT_3f42161d);
    FUN_400d5948(auStack_58,auStack_34);
    FUN_400da510(0x3ffc4218,auStack_34);
    FUN_400f0a50(auStack_34);
    FUN_400d73a8(auStack_78);
    goto LAB_400d7622;
  }
  if (2 < (int)param_2) goto LAB_400d7639;
  if (param_2 == (int *)0x0) {
    pcVar3 = "ting...";
    if ((*param_1 != 4) && (pcVar3 = "nection", *param_1 != 3)) goto LAB_400d7622;
  }
  else {
    pcVar3 = "ionMode";
    if (param_2 != (int *)0x1) goto LAB_400d7622;
  }
LAB_400d7759:
  do {
    FUN_400f0780(0x3ffc5490,pcVar3);
LAB_400d7622:
    do {
      while( true ) {
        param_2 = piStack_24;
        param_1 = _DAT_3ffc5708;
        memw();
        memw();
        if (piStack_24 == _DAT_3ffc5708) {
          return;
        }
        func_0x40082ecc();
LAB_400d7639:
        if (4 < (int)param_2) break;
        pcVar3 = "ellular";
        if (param_2 != (int *)0x3) {
          pcVar3 = " Failed";
        }
        FUN_400f06a4(0x3ffc5490,"necting",pcVar3);
        pcVar3 = &DAT_3f4027d9;
        if ((*param_1 == 4) || (pcVar3 = "nection", *param_1 == 3)) goto LAB_400d7759;
      }
    } while ((param_2 != (int *)&DAT_00000005) ||
            (FUN_400f0780(0x3ffc5490,"l retry"), *param_1 != 4));
    pcVar3 = "etected";
  } while( true );
}

