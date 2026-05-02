// Function : FUN_400d9e2c
// Address  : 0x400d9e2c
// Size     : 275 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d9e2c(uint param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  piVar2 = (int *)0x3ffc5490;
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) goto LAB_400d9e70;
  uVar3 = (uint)param_2[3] >> 0x18 & 0x7f;
  do {
    if (uVar3 != 0) {
      FUN_400f0d18(param_1,param_2);
      FUN_400f0be8(auStack_34,"rovided");
      uVar1 = FUN_400f10c0(auStack_34,param_2);
      FUN_400f0768(piVar2,uVar1);
      FUN_400f0a50(auStack_34);
      FUN_400f1ab4(3000);
      *(undefined1 *)(param_1 + 0x10) = 1;
      FUN_400f0780(piVar2,"h APN: ");
      FUN_400f0be8(auStack_34,"rk with APN: ");
      uVar1 = FUN_400f10c0(auStack_34,param_2);
      FUN_400f0768(piVar2,uVar1);
      FUN_400f0a50(auStack_34);
      FUN_400f0be8(auStack_34,"sfully!");
      FUN_400d9e14(auStack_44,param_1);
      uVar1 = FUN_400f10c0(auStack_34,auStack_44);
      FUN_400f0768(piVar2,uVar1);
      FUN_400f0a50(auStack_44);
      FUN_400f0a50(auStack_34);
      param_1 = (uint)*(byte *)(param_1 + 0x10);
      goto LAB_400d9e5a;
    }
    do {
      FUN_400f0780(piVar2,"0.0.0.0");
      param_1 = 0;
LAB_400d9e5a:
      piVar2 = piStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (piStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400d9e70:
    } while (*param_2 == 0);
    uVar3 = param_2[2];
  } while( true );
}

