// Function : FUN_40124450
// Address  : 0x40124450
// Size     : 256 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40124450(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined1 auStack_8c [104];
  int *piStack_24;
  
  piVar5 = (int *)0x0;
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  param_1[4] = 8;
  param_1[0xe] = 0;
  *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) & 0xbe | 1;
  memw();
  piVar4 = param_1 + 2;
  piVar3 = param_1 + 0x23;
  do {
    piVar1 = piVar3;
    if ((param_1[0x6f] & 0xd42U) == 0) goto LAB_401244b8;
    memw();
    piVar1 = (int *)FUN_40124438(piVar4,piVar5);
    if (piVar1 != (int *)0x0) goto LAB_401244b8;
    do {
      while( true ) {
        param_1 = _DAT_3ffc5708;
        memw();
        memw();
        if (piStack_24 == _DAT_3ffc5708) {
          return;
        }
        (*(code *)&SUB_40082ec4)();
        piVar1 = piVar3;
LAB_401244b8:
        piVar5 = piVar1;
        memw();
        FUN_401061d0(piVar5,0x20," deinit",*param_1 + 0x5c,piVar4,param_1 + 0x13,param_1 + 0x1b,
                     auStack_8c,param_1[0x6f],param_1[0x6e]);
        iVar2 = FUN_4012428c(param_1[0x6f],auStack_8c,param_1[0x65],param_1[0x66]);
        if (iVar2 != 0) break;
        param_1[0x70] = 0;
        memw();
        FUN_4018509c(0x40125468,*param_1,param_1);
        piVar4 = (int *)param_1[0x6f];
        if ((((uint)piVar4 & 0xd42) != 0) && (piVar5 != param_1 + 0x23)) {
          (*(code *)&SUB_4008b3d0)(param_1 + 0x23,piVar5,0x20);
        }
        param_1[0x11] = 1;
        memw();
        (*(code *)&SUB_4008b3d0)(param_1 + 0x2b,auStack_8c,0x68);
        piVar3 = (int *)0x1;
        param_1[0x45] = 1;
        memw();
      }
    } while ((param_1[0x6f] & 0xd42U) == 0);
  } while( true );
}

