// Function : FUN_400eff10
// Address  : 0x400eff10
// Size     : 137 bytes


void FUN_400eff10(int *param_1)

{
  int iVar1;
  int iStack_34;
  uint uStack_30;
  uint auStack_2c [2];
  char cStack_24;
  
  iStack_34 = 0;
  FUN_40184824(param_1[5],&iStack_34);
  if (iStack_34 == 0) {
    func_0x40091740();
    return;
  }
  do {
    while( true ) {
      do {
        iVar1 = func_0x4008fecc(iStack_34,auStack_2c,0xffffffff);
      } while (iVar1 == 0);
      if (auStack_2c[0] != 2) break;
LAB_400eff40:
      if (param_1[0xe] != 0) {
        uStack_30 = auStack_2c[0];
        (*(code *)param_1[0xf])(param_1 + 0xc,&uStack_30);
      }
    }
    if (auStack_2c[0] < 3) {
      if (auStack_2c[0] == 0) {
        if (((param_1[10] != 0) && (iVar1 = (**(code **)(*param_1 + 0x18))(param_1), 0 < iVar1)) &&
           (((char)param_1[0x10] == '\0' || (cStack_24 != '\0')))) {
          if (param_1[10] == 0) {
            FUN_40170584();
          }
          (*(code *)param_1[0xb])(param_1 + 8);
        }
      }
      else if (auStack_2c[0] == 1) goto LAB_400eff40;
    }
    else if (((auStack_2c[0] == 4) || (auStack_2c[0] < 4)) || (auStack_2c[0] == 5))
    goto LAB_400eff40;
  } while( true );
}

