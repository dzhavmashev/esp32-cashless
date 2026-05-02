// Function : FUN_400eced8
// Address  : 0x400eced8
// Size     : 205 bytes


undefined4 FUN_400eced8(undefined4 *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined1 auStack_40 [2];
  undefined1 auStack_3e [2];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  uint uStack_34;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [40];
  
  if ((*(char *)(param_1 + 1) == '\x01') && ((param_2 == 0) == 0)) {
    uVar1 = func_0x4008c024(param_2);
    uVar3 = 10;
    if (uVar1 < 0x10) {
      uStack_34 = (uint)(param_2 == 0);
      iVar2 = FUN_400f97f8(*param_1,param_2,&uStack_42);
      uVar3 = 0;
      if (iVar2 != 0) {
        iVar2 = FUN_400f983c(*param_1,param_2,&uStack_41);
        uVar3 = 1;
        if (iVar2 != 0) {
          iVar2 = FUN_400f9880(*param_1,param_2,auStack_40);
          uVar3 = 2;
          if (iVar2 != 0) {
            iVar2 = FUN_400f98c4(*param_1,param_2,auStack_3e);
            uVar3 = 3;
            if (iVar2 != 0) {
              iVar2 = FUN_400f9908(*param_1,param_2,auStack_3c);
              uVar3 = 4;
              if (iVar2 != 0) {
                iVar2 = FUN_400f994c(*param_1,param_2,auStack_38);
                uVar3 = 5;
                if (iVar2 != 0) {
                  iVar2 = FUN_400f9990(*param_1,param_2,auStack_30);
                  uVar3 = 6;
                  if (iVar2 != 0) {
                    iVar2 = FUN_400f99d4(*param_1,param_2,auStack_28);
                    uVar3 = 7;
                    if (iVar2 != 0) {
                      iVar2 = FUN_400f9a18(*param_1,param_2,0,&uStack_34);
                      uVar3 = 8;
                      if (iVar2 != 0) {
                        iVar2 = FUN_400f9a2c(*param_1,param_2,0,&uStack_34);
                        uVar3 = 10;
                        if (iVar2 == 0) {
                          uVar3 = 9;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    uVar3 = 10;
  }
  return uVar3;
}

