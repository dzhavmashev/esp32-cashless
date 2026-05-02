// Function : FUN_400fb29c
// Address  : 0x400fb29c
// Size     : 396 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fb29c(undefined1 *param_1,uint param_2,uint param_3,undefined1 *param_4,int param_5,
                 uint param_6,undefined1 param_7)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 local_64 [4];
  undefined4 uStack_60;
  undefined2 uStack_4c;
  undefined2 uStack_4a;
  undefined4 uStack_48;
  undefined1 auStack_44 [32];
  uint uStack_24;
  
  param_2 = param_2 & 0xff;
  param_3 = param_3 & 0xff;
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  puVar1 = (undefined1 *)0x110b;
  if (*(int *)(param_1 + 0xc) == 0) goto LAB_400fb2cd;
  if (*(int *)(param_1 + 0xc) == -1) goto LAB_400fb2ec;
  do {
    puVar1 = (undefined1 *)0x110a;
    if (*(int *)(param_1 + 0xc) != -4) {
      uVar2 = (*(code *)&SUB_4008c01c)(param_4);
      puVar1 = (undefined1 *)0x1109;
      if ((uVar2 < 0x10) && (puVar1 = &DAT_0000110e, param_6 < 0xfa1)) {
        iVar3 = FUN_40184a1c(param_3);
        if (iVar3 == 0) {
          puVar1 = (undefined1 *)0x102;
          if (8 < param_6) goto LAB_400fb2cd;
          iVar3 = 1;
          uVar2 = 0x20;
        }
        else {
          uVar2 = (param_6 + 0x1f & 0xffffffe0) + 0x20;
          iVar3 = (param_6 + 0x1f >> 5) + 1;
        }
        puVar1 = (undefined1 *)0x110a;
        if ((*(int *)(param_1 + 0x38) != -1) && ((uint)(*(int *)(param_1 + 0x38) + iVar3) < 0x7f)) {
          FUN_400fb060(auStack_44,param_2,param_3,uVar2 >> 5,param_4,param_7);
          (*(code *)&SUB_4008b3d0)(local_64,auStack_44,0x20);
          puVar1 = (undefined1 *)
                   FUN_400faef8(param_1 + 0x44,local_64,*(undefined4 *)(param_1 + 0x38));
          if (puVar1 == (undefined1 *)0x0) {
            iVar3 = FUN_40184a1c(param_3);
            if (iVar3 == 0) {
              (*(code *)&SUB_4008b3d0)(&uStack_4c,param_5,param_6);
              uStack_60 = FUN_400fc574(local_64);
LAB_400fb38a:
              memw();
              puVar1 = (undefined1 *)FUN_400fb184(param_1,local_64);
            }
            else {
              uStack_48 = FUN_400fc5c8(param_5,param_6);
              uStack_4c = (undefined2)param_6;
              uStack_4a = 0xffff;
              memw();
              memw();
              uStack_60 = FUN_400fc574(local_64);
              memw();
              puVar4 = (undefined1 *)FUN_400fb184(param_1,local_64);
              puVar1 = puVar4;
              if (puVar4 == (undefined1 *)0x0) {
                uVar2 = param_6 & 0x1f;
                param_6 = param_6 - uVar2;
                if (param_6 != 0) {
                  memw();
                  puVar1 = (undefined1 *)FUN_400fb1e8(param_1,param_5,param_6);
                  if (puVar1 != (undefined1 *)0x0) goto LAB_400fb2cd;
                }
                puVar1 = puVar4;
                if (uVar2 != 0) {
                  local_64[0] = 0xff;
                  memw();
                  memw();
                  (*(code *)&SUB_4008b3d0)(local_64,param_5 + param_6,uVar2);
                  goto LAB_400fb38a;
                }
              }
            }
          }
        }
      }
    }
LAB_400fb2cd:
    do {
      param_1 = puVar1;
      param_3 = uStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (uStack_24 == _DAT_3ffc5708) {
        return;
      }
      memw();
      (*(code *)&SUB_40082ec4)();
      param_4 = &DAT_3ffc5708;
LAB_400fb2ec:
      puVar1 = (undefined1 *)FUN_400fb0f4(param_1);
    } while (puVar1 != (undefined1 *)0x0);
  } while( true );
}

