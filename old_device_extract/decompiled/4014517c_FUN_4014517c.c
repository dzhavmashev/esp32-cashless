// Function : FUN_4014517c
// Address  : 0x4014517c
// Size     : 223 bytes


int FUN_4014517c(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar3 = -0x2800;
  }
  else {
    if ((param_3 != 0) && (*(char *)(param_2 + param_3 + -1) == '\0')) {
      memw();
      iVar3 = (*(code *)&SUB_4008ca5c)(param_2,"ATE----------BEGIN CERTIFICATE-----");
      if (iVar3 != 0) {
        memw();
        iVar3 = 0;
        iVar5 = 0;
        bVar1 = false;
LAB_4014522b:
        do {
          if (param_3 < 2) {
LAB_4014522e:
            if (bVar1) {
              return iVar5;
            }
            if (iVar3 != 0) {
              return iVar3;
            }
            return -0x2780;
          }
          FUN_401397d0(&uStack_2c);
          memw();
          iVar4 = FUN_401397e4(&uStack_2c,"ATE----------BEGIN CERTIFICATE-----","E-----\n",param_2,0
                               ,0,&local_30);
          iVar2 = local_30;
          if (iVar4 == 0) {
            iVar4 = FUN_4014514c(param_1,uStack_2c,uStack_28);
            param_3 = param_3 - iVar2;
            param_2 = param_2 + iVar2;
            FUN_40139ae0(&uStack_2c);
            if (iVar4 == 0) {
              bVar1 = true;
              memw();
              goto LAB_4014522b;
            }
            if (iVar4 == -0x2880) {
              return -0x2880;
            }
          }
          else {
            if (iVar4 == -0x1480) {
              return -0x1480;
            }
            if (iVar4 == -0x1080) goto LAB_4014522e;
            FUN_40139ae0(&uStack_2c);
            param_3 = param_3 - local_30;
            param_2 = param_2 + local_30;
          }
          if (iVar3 == 0) {
            iVar3 = iVar4;
          }
          iVar5 = iVar5 + 1;
        } while( true );
      }
    }
    iVar3 = FUN_4014514c(param_1,param_2,param_3);
  }
  return iVar3;
}

