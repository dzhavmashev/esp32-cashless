// Function : FUN_400fa0e8
// Address  : 0x400fa0e8
// Size     : 286 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fa0e8(int param_1,uint param_2,uint param_3,int param_4,undefined1 *param_5,
                 undefined1 *param_6)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint in_t0;
  uint uStack_64;
  uint uStack_5c;
  undefined1 *puStack_58;
  undefined4 uStack_48;
  undefined1 auStack_44 [24];
  undefined1 *puStack_2c;
  byte bStack_28;
  byte bStack_27;
  uint uStack_24;
  
  param_2 = param_2 & 0xff;
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  uStack_48 = 0;
  memw();
  iVar1 = FUN_400f9c84(param_1,param_2,0x48,param_3,&uStack_48,auStack_44,0xff,0xff);
  puVar2 = (undefined1 *)0xff;
  puVar3 = param_5;
  if (iVar1 != 0) goto LAB_400fa140;
  uStack_5c = (uint)bStack_27;
  puStack_58 = (undefined1 *)(uint)bStack_28;
  puVar2 = auStack_44;
  uVar4 = 0;
  puVar3 = (undefined1 *)0x0;
  param_6 = puStack_2c;
  if (puStack_2c == param_5) goto LAB_400fa194;
LAB_400fa13e:
  iVar1 = -1;
LAB_400fa140:
  do {
    do {
      uVar4 = in_t0;
      param_1 = iVar1;
      param_3 = uStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (uStack_24 == _DAT_3ffc5708) {
        return;
      }
      memw();
      (*(code *)&SUB_40082ec4)();
      uStack_64 = uVar4;
      in_t0 = uVar4;
      do {
        memw();
        iVar1 = FUN_400fb884(uStack_48,param_2,0x42,param_3,puVar3 + param_4,
                             *(undefined2 *)(puVar2 + 0x18),param_6,uStack_64);
        if (iVar1 != 0) goto LAB_400fa140;
        param_6 = (undefined1 *)(uStack_5c + uVar4);
        if (param_6 != (undefined1 *)(uint)(byte)puVar2[3]) goto LAB_400fa13e;
        uVar4 = uVar4 + 1;
        puVar3 = puVar3 + *(ushort *)(puVar2 + 0x18);
LAB_400fa194:
        param_6 = (undefined1 *)(uVar4 & 0xff);
        if (puStack_58 <= param_6) {
          puVar3 = puVar3 + -(int)param_5;
          iVar1 = -(uint)(puVar3 != (undefined1 *)0x0);
          goto LAB_400fa140;
        }
        param_6 = (undefined1 *)((uint)(param_6 + uStack_5c) & 0xff);
        uStack_64 = 0xff;
        memw();
        iVar1 = FUN_400f9c84(param_1,param_2,0x42,param_3,&uStack_48,puVar2,param_6,0xff);
      } while (iVar1 == 0);
      puVar2 = (undefined1 *)0x1102;
    } while (iVar1 != 0x1102);
    puVar2 = param_5;
    if (puVar3 != param_5) goto LAB_400fa13e;
    memw();
    FUN_400fa000(param_1,param_2,param_3,0xff);
  } while( true );
}

