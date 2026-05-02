// Function : FUN_40136968
// Address  : 0x40136968
// Size     : 164 bytes


int FUN_40136968(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_c0 [12];
  undefined1 auStack_b4 [12];
  undefined1 auStack_a8 [12];
  undefined1 auStack_9c [156];
  
  if ((*param_1 != 0) && (*param_1 == *param_2)) {
    iVar1 = FUN_401860ec(param_1 + 0x22,param_2 + 0x22);
    if (iVar1 == 0) {
      iVar1 = FUN_401860ec(param_1 + 0x25,param_2 + 0x25);
      if (iVar1 == 0) {
        iVar1 = FUN_401860ec(param_1 + 0x28,param_2 + 0x28);
        if (iVar1 == 0) {
          FUN_4013562c(auStack_c0);
          FUN_40135644(auStack_9c);
          FUN_40135750(auStack_9c,param_2);
          iVar1 = FUN_401367a4(auStack_9c,auStack_c0,param_2 + 0x1f,param_2 + 10,0,0);
          if (iVar1 == 0) {
            iVar1 = FUN_401860ec(auStack_c0,param_2 + 0x22);
            if ((iVar1 == 0) && (iVar1 = FUN_401860ec(auStack_b4,param_2 + 0x25), iVar1 == 0)) {
              iVar2 = FUN_401860ec(auStack_a8,param_2 + 0x28);
              iVar1 = 0;
              if (iVar2 == 0) goto LAB_401369f4;
            }
            iVar1 = -0x4f80;
          }
LAB_401369f4:
          FUN_40135340(auStack_c0);
          FUN_401356b4(auStack_9c);
          return iVar1;
        }
      }
    }
  }
  return -0x4f80;
}

